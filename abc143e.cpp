#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max() / 4;
signed main() {
	int n, m, l;
	cin >> n >> m >> l;
	vector<vector<int>> use(n + 1, vector<int>(n + 1, INF));
	auto dis = use;
	while (m--) {
		int a, b, w;
		cin >> a >> b >> w;
		use[a][b] = min(use[a][b], w);
		use[b][a] = min(use[b][a], w);
	}
	for (int k = 1;k <= n;k++) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) use[i][j] = min(use[i][k] + use[k][j], use[i][j]);
		}
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (i != j and use[i][j] <= l) dis[i][j] = 1;
		}
	}
	for (int k = 1;k <= n;k++) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << (dis[a][b] == INF ? -1 : dis[a][b] - 1) << '\n';
	}
}

