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
		t.assign(2 * sz, 0);
	}
	void build(vector<int> &v) {
		for (int i = 0;i < v.size();i++) t[sz + i] = v[i];
		for (int i = sz - 1;i > 0;i--) t[i] = t[i * 2] + t[(i * 2) | 1];
	}
	void upd(int l, int r, int x) {
		for (l = sz + l, r = sz + r - 1;l <= r;l /= 2, r /= 2) {
			if (l & 1) t[l++] += x;
			if (!(r & 1)) t[r--] += x;
		}
	}
	int ask(int i) {
		int ans = 0;
		for (i += sz;i > 0;i /= 2) ans += t[i];
		return ans;
	}
};
signed main() {
	IO;
	int n, q;
	cin >> n >> q;
	segment_tree st(n);
	vector<int> v(n);
	st.build(v);
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			st.upd(l, r, x);
		}
		else {
			int x;
			cin >> x;
			cout << st.ask(x) << '\n';
		}
	}
}
