#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n);
	while (m--) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	vector<vector<int>> dis(1 << n, vector<int>(n, 1e9));
	queue<pair<int, int>> q;
	for (int i = 0;i < n;i++) {
		q.push({1 << i, i});
		dis[1 << i][i] = 1;
	}
	while (!q.empty()) {
		auto [t, x] = q.front();
		q.pop();
		for (auto y : v[x]) {
			int nt = t ^ (1 << y);
			if (dis[nt][y] == 1e9) {
				q.push({nt, y});
				dis[nt][y] = dis[t][x] + 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1;i < (1 << n);i++) {
		int x = 1e9;
		for (int j = 0;j < n;j++) {
			x = min(x, dis[i][j]);
		}
		if (x != 1e9) ans += x;
	}
	cout << ans;
}
