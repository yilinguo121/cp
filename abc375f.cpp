#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max() / 6;
signed main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> a(m), b(m), w(m);
	for (int i = 0;i < m;i++) {
		cin >> a[i] >> b[i] >> w[i];
		a[i]--, b[i]--;
	}
	vector<array<int, 3>> v;
	vector<bool> block(m);
	for (int i = 0;i < q;i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int k;
			cin >> k;
			v.push_back({1, k - 1, 0});
			block[k - 1] = 1;
		}
		else {
			int x, y;
			cin >> x >> y;
			v.push_back({2, x - 1, y - 1});
		}
	}
	vector<vector<int>> dis(n, vector<int>(n, INF));
	reverse(v.begin(), v.end());
	for (int i = 0;i < n;i++) dis[i][i] = 0;
	for (int i = 0;i < m;i++) {
		if (block[i]) continue;
		dis[a[i]][b[i]] = min(dis[a[i]][b[i]], w[i]);
		dis[b[i]][a[i]] = min(dis[b[i]][a[i]], w[i]);
	}
	for (int k = 0;k < n;k++) {
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	vector<int> ans;
	for (auto [t, x, y] : v) {
		if (t == 2) ans.push_back(dis[x][y]);
		else {
			for (int i = 0;i < n;i++) {
				for (int j = 0;j < n;j++) {
					dis[i][j] = min({dis[i][j], dis[i][a[x]] + w[x] + dis[b[x]][j], dis[i][b[x]] + w[x] + dis[a[x]][j]});
				}
			}
		}
	}
	reverse(ans.begin(), ans.end());
	for (auto x : ans) cout << (x == INF ? -1 : x) << '\n';
}

