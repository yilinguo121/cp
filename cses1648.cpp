#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
struct BIT {
	int n;
	vector<int> tree;
	vector<int> v;
	BIT (int n = 0) : n(n), tree(n + 1, 0), v(n + 1, 0) {}
	void upd(int i, int x) {
		v[i] += x;
		for (;i <= n;i += i & -i) tree[i] += x;
	}
	int get(int i) {
		int s = 0;
		for (;i > 0;i -= i & -i) s += tree[i];
		return s;
	}
	int sum(int l, int r) {return get(r) - get(l - 1);}
};
signed main() {
	IO
	int n, q;
	cin >> n >> q;
	BIT bit(n);
	for (int i = 1, x;i <= n;i++) {
		cin >> x;
		bit.upd(i, x);
	}
	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			bit.upd(x, -bit.v[x]);
			bit.upd(x, y);
		}
		else cout << bit.sum(x, y) << '\n';
	}
}

