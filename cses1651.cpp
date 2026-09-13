#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
struct BIT {
	int n;
	vector<int> tree;
	BIT (int n = 0) : n(n), tree(n + 1, 0) {}
	void upd(int i, int x = 1) {
		for (;i > 0; i -= i & -i) tree[i] += x;
	}
	int get(int i) {
		int s = 0;
		for (;i <= n;i += i & -i) s += tree[i];
		return s;
	}
};
signed main() {
	IO;
	int n, q;
	cin >> n >> q;
	BIT bit(n);
	for (int i = 1;i <= n;i++) {
		int x;
		cin >> x;
		bit.upd(i, x);
		bit.upd(i - 1, -x);
	}
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			bit.upd(r, x);
			bit.upd(l - 1, -x);
		}
		else {
			int x;
			cin >> x;
			cout << bit.get(x) << '\n';
		}
	}
}
