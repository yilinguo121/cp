#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<vector<int>>> st(6, vector<vector<int>>(max(n, m) + 5, vector<int>(20))); //0 amx, 1 amn, 2 apmn, 3 anmx, 4 bmx, 5 bmn
	vector<vector<int>> v(6, vector<int>(max(n, m) + 5));
	for (int i = 1;i <= n;i++) {
		cin >> v[0][i], v[1][i] = v[0][i];
		v[2][i] = (v[0][i] >= 0 ? v[0][i] : INF);
		v[3][i] = (v[0][i] <= 0 ? v[0][i] : -INF);
	}
	for (int i = 1;i <= m;i++) cin >> v[4][i], v[5][i] = v[4][i];
	for (int k = 0;k < 6;k++) {
		int sz = (k < 4 ? n : m);
		for (int i = 1;i <= sz;i++) st[k][i][0] = v[k][i];
		for (int j = 1;j < 20;j++) {
			for (int i = 1;i + (1 << j) - 1 <= sz;i++) {
				int x = st[k][i][j - 1], y = st[k][i + (1 << (j - 1))][j - 1];
				st[k][i][j] = (k == 0 or k == 3 or k == 4 ? max(x, y) : min(x, y));
			}
		}
	}
	auto get = [&](int k, int l, int r, bool flag) {
		int lg = log2(r - l + 1);
		int x = st[k][l][lg], y = st[k][r - (1 << lg) + 1][lg];
		return (flag ? max(x, y) : min(x, y));
	};
	while (q--) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		int bmx = get(4, l2, r2, 1), bmn = get(5, l2, r2, 0), ans = -INF;
		vector<int> a;
		a.push_back(get(0, l1, r1, 1));
		a.push_back(get(1, l1, r1, 0));
		a.push_back(get(2, l1, r1, 0));
		a.push_back(get(3, l1, r1, 1));
		for (auto x : a) {
			if (x == INF or x == -INF) continue;
			ans = max((x > 0 ? x * bmn : x * bmx), ans);
		}
		cout << ans << '\n';
	}
}
