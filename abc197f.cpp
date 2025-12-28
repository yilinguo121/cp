#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<long long>::max();
signed main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> v(n + 1);
	while (m--) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		v[a].push_back({b, c - 'a'});
		v[b].push_back({a, c - 'a'});
	}
	vector<vector<int>> dis(n + 1, vector<int>(n + 1, INF));
	queue<tuple<int, int, int>> q;
	q.push({1, n, 0});
	dis[1][n] = 0;
	while (!q.empty()) {
		auto [x, y, z] = q.front();
		q.pop();
		if (z > dis[x][y]) continue;
		for (auto [nx, a] : v[x]) {
			for (auto [ny, b] : v[y]) {
				if (b == a and z + 1 < dis[nx][ny]) {
					dis[nx][ny] = z + 1;
					q.push({nx, ny, z + 1});
				}
			}
		}
	}
	int ans = INF;
	for (int i = 1;i <= n;i++) {
		if (dis[i][i] != INF) ans = min(ans, dis[i][i] * 2);
		for (auto [j, w] : v[i]) if (dis[i][j] != INF) ans = min(ans, dis[i][j] * 2 + 1);
	}
	cout << (ans == INF ? -1 : ans);
}
