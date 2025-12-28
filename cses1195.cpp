#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> v(n + 1);
	while (m--) {
		int a, b, w;
		cin >> a >> b >> w;
		v[a].push_back({b, w});
	}
	priority_queue<tuple<int, bool, int>, vector<tuple<int, bool, int>>, greater<tuple<int, bool, int>>> q;
	vector<vector<int>> dis(n + 1, vector<int>(2, INF));
	q.push({0, 0, 1});
	dis[1][0] = 0;
	while (!q.empty()) {
		auto [d, use, t] = q.top();
		q.pop();
		if (d != dis[t][use]) continue;
		for (auto [nt, nd] : v[t]) {
			if (dis[nt][use] > d + nd) {
				dis[nt][use] = d + nd;
				q.push({dis[nt][use], use, nt});
			}
			if (!use and dis[nt][1] > d + nd / 2) {
				dis[nt][1] = d + nd / 2;
				q.push({dis[nt][1], 1, nt});
			}
		}
	}
	cout << min(dis[n][0], dis[n][1]);
}
