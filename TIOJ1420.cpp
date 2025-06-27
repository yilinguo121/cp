#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//const long long INF = numeric_limits<int>::max();
bool mp[10001][10001], vis[10001][10001];
int main() {
	IO
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, int>> v(k);
	for (int i = 0;i < k;i++) {
		cin >> v[i].first >> v[i].second;
		mp[v[i].first][v[i].second] = 1;
	}
	int ans = 0;
	for (auto [x, y] : v) {
		if (!vis[x][y]) {
			ans++;
			queue<pair<int, int>> q;
			q.push({x, y});
			vis[x][y] = 1;
			while (!q.empty()) {
				auto [nx, ny] = q.front();
				q.pop();
				for (int i = max(1, nx - 2);i <= min(n, nx + 2);i++) {
					for (int j = max(1, ny - 2);j <= min(m, ny + 2);j++) {
						if (!vis[i][j] and mp[i][j]) {
							q.push({i, j});
						}
						vis[i][j] = 1;
					}
				}
			}
		}
	}
	cout << ans;
}

