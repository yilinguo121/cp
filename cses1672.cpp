#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max() / 2;
signed main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> v(n, vector<int>(n, INF));
	for (int i = 0;i < n;i++) v[i][i] = 0;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		v[a][b] = min(v[a][b], c);
		v[b][a] = min(v[b][a], c);
	}
	for (int k = 0;k < n;k++) {
		for (int i = 0;i < n;i++) {
			if (v[i][k] == INF) continue;
			for (int j = 0;j < n;j++) {
				if (v[k][j] == INF) continue;
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
			}
		}
	}
	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << (v[a - 1][b - 1] == INF ? -1 : v[a - 1][b - 1]) << '\n';
	}
}
