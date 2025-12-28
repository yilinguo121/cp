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
		v[b].push_back({a, w});
	}
	vector<int> dis(n + 1), a(n + 1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		dis[i] = a[i];
		q.push({dis[i], i});
	}
	while (!q.empty()) {
		auto [d, t] = q.top();
		q.pop();
		if (d != dis[t]) continue;
		for (auto [nt, nd] : v[t]) {
			if (d + nd * 2 < dis[nt]) {
				dis[nt] = d + nd * 2;
				q.push({dis[nt], nt});
			}
		}
	}
	for (int i = 1;i <= n;i++) cout << dis[i] << ' ';
}

