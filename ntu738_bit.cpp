#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
struct BIT {
	int n;
	vector<int> tree;
	BIT (int n = 0) : n(n), tree(n + 1, 0) {}
	void upd(int i, int x = 1) {for (;i <= n;i += i & -i) tree[i] += x;}
	int get(int i) {
		int s = 0;
		for (;i > 0;i -= i & -i) s += tree[i];
		return s;
	}
	int sum(int l, int r) {return get(r) - get(l - 1);}
};
signed main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end());
	vector<int> rk(n);
	for (int i = n - 1;i >= 0;i--) rk[v[i].second] = i + 1;
	BIT sum(n), cnt(n);
	int ans = 0;
	for (int i = n - 1;i >= 0;i--) {
		ans += cnt.get(rk[i] - 1) * v[rk[i] - 1].first + sum.get(rk[i] - 1);
		cnt.upd(rk[i]);
		sum.upd(rk[i], v[rk[i] - 1].first);
	}
	cout << ans;
}
