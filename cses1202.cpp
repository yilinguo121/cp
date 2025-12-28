#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max(), mod = 1000000007;
signed main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> v(n + 1);
	while (m--) {
		int a, b, w;
		cin >> a >> b >> w;
		v[a].push_back({b, w});
	}
	vector<int> dis(n + 1, INF), way(n + 1, 0), mn(n + 1, INF), mx(n + 1, 0);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, 1});
	dis[1] = mn[1] = 0, way[1] = 1;
	while (!q.empty()) {
		auto [d, t] = q.top();
		q.pop();
		if (d != dis[t]) continue;
		for (auto [nt, nd] : v[t]) {
			if (d + nd < dis[nt]) {
				dis[nt] = d + nd;
				way[nt] = way[t];
				mn[nt] = mn[t] + 1;
				mx[nt] = mx[t] + 1;
				q.push({d + nd, nt});
			}
			else if (d + nd == dis[nt]){
				way[nt] = (way[t] + way[nt]) % mod;
				mn[nt] = min(mn[nt], mn[t] + 1);
				mx[nt] = max(mx[nt], mx[t] + 1);
			}
		}
	}
	cout << dis[n] << ' ' << way[n] << ' ' << mn[n] << ' ' << mx[n];
}

