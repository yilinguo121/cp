#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
struct segment_tree {
	int sz;
	vector<int> t;
	segment_tree(int n = 0) {init(n);}
	void init(int n) {
		for (sz = 1;sz < n;sz *= 2);
		t.assign(2 * sz, INF);
	}
	void build(vector<int> &v) {
		for (int i = 0;i < v.size();i++) t[sz + i] = v[i];
		for (int i = sz - 1;i > 0;i--) t[i] = min(t[i * 2], t[(i * 2) | 1]);
	}
	void upd(int x, int k) {
		int i = sz + x - 1;
		t[i] = k;
		for (i /= 2;i > 0;i /= 2) t[i] = min(t[i * 2], t[(i * 2) | 1]);
	}
	int ask(int l, int r) {
		int ans = INF;
		for (l = sz + l - 1, r = sz + r - 1;l <= r;l /= 2, r /= 2) {
			if (l & 1) ans = min(ans, t[l++]);
			if (!(r & 1)) ans = min(ans, t[r--]);
		}
		return ans;
	}
};
signed main() {
	IO
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	segment_tree st(n);
	st.build(v);
	while (q--) {
		int type, x, y;
		cin >> type >> x >> y;
		if (type == 1) st.upd(x, y);
		else cout << st.ask(x, y) << '\n';
	}
}
