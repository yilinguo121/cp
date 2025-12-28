#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
struct BIT{
	int n; vector<int> b;
	BIT(int n = 0) {init(n);}
	void init(int x) {
		n = x + 1;
		b.assign(n + 2, 0);
	}
	void add(int i, int v) {
		for (;i <= n;i += i & -i) b[i] += v;
	}
	void range_add(int l, int r, int v) {
		if (l <= r) {
			add(l, v);
			add(r+1,-v);
		}
	}
	int get(int i) {
		int s = 0;
		for (;i;i -= i & -i) s+=b[i];
		return s;
	} // 0=S1, 1=S2
};
signed main() {
	IO
	int n;
	cin >> n;
	vector<int> pos(n + 1);
	for (int i = 1, x;i <= n;i++) {
		cin >> x;
		pos[x] = i;
	}
	vector<pair<int, int>> s1, s2;
	s2.push_back({1, n});
	BIT bit(n);
	bit.range_add(1, n, 1);
	int ans = 0;
	for (int i = 1;i <= n;i++) {
		int p = pos[i], t = bit.get(p);
		auto &from = (t ? s2 : s1), &to = (t ? s1 : s2);
		while (1) {
			auto [l, r] = from.back();
			if (l <= p and p <= r) break;
			ans += r - l + 1;
			bit.range_add(l, r, t ? -1 : 1);
			to.push_back({l, r});
			from.pop_back();
		}
		auto [l, r] = from.back();
		if (t) {
			ans += p - l + 1;
			if (l <= p - 1) {
				bit.range_add(l, p - 1, -1);
				to.push_back({l, p - 1});
			}
			if (p + 1 <= r) from.back().first = p + 1;
			else from.pop_back();
		}
		else {
			ans += r - p + 1;
			if (p + 1 <= r) {
				bit.range_add(p + 1, r, 1);
				to.push_back({p + 1, r});
			}
			if (l <= p - 1) from.back().second = p - 1;
			else from.pop_back();
		}
	}
	cout << ans;
}

