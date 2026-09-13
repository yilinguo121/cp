#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<vector<vector<int>>> st;
vector<int> v;
bool cmp(int x, int y) {
	if (x == -1) return 0;
	if (y == -1) return 1;
	if (v[x] != v[y]) return v[x] < v[y];
	return x < y;
}
void upd(int &f, int &s, int p) {
	if (cmp(p, f)) s = f, f = p;
	if (p != f and cmp(p, s)) s = p;
}
int main() {
	IO
	int n, q;
	cin >> n >> q;
	v.resize(n);
	st.resize(18, vector<vector<int>>(n, vector<int>(2, -1)));
	for (int i = 0;i < n;i++) cin >> v[i], st[0][i][0] = i;
	for (int k = 1;(1 << k) <= n;k++) {
		for (int i = 0;i + (1 << k) - 1 < n;i++) {
			int f = -1, s = -1;
			upd(f, s, st[k - 1][i][0]);
			upd(f, s, st[k - 1][i][1]);
			upd(f, s, st[k - 1][i + (1 << (k - 1))][0]);
			upd(f, s, st[k - 1][i + (1 << (k - 1))][1]);
			st[k][i][0] = f, st[k][i][1] = s;
		}
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		int lg = log2(r - l + 1), f = -1, s = -1;
		upd(f, s, st[lg][l][0]);
		upd(f, s, st[lg][l][1]);
		upd(f, s, st[lg][r - (1 << lg) + 1][0]);
		upd(f, s, st[lg][r - (1 << lg) + 1][1]);
		cout << s + 1 << '\n';
	}
}
