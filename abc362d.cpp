#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1;i <= n;i++) cin >> a[i];
	vector<vector<pair<int, int>>> v(n + 1);
	while (m--) {
		int a, b, w;
		cin >> a >> b >> w;
		v[a].push_back({b, w});
		v[b].push_back({a, w});
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	vector<int> dis(n + 1, INF);
	q.push({a[1], 1});
	dis[1] = a[1];
	while (!q.empty()) {
		auto [d, t] = q.top();
		q.pop();
		if (d != dis[t]) continue;
		for (auto [nt, nd] : v[t]) {
			if (nd + a[nt] + d < dis[nt]) {
				dis[nt] = nd + a[nt] + d;
				q.push({dis[nt], nt});
			}
		}
	}
	for (int i = 2;i <= n;i++) cout << dis[i] << ' ';
}

