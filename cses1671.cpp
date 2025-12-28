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
	vector<int> dis(n + 1, INF);
	dis[1] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, 1});
	while (!q.empty()) {
		auto [w, t] = q.top();
		q.pop();
		if (w != dis[t]) continue;
		for (auto [nt, nw] : v[t]) {
			if (dis[nt] > w + nw) {
				dis[nt] = w + nw;
				q.push({dis[nt], nt});
			}
		}
	}
	for (int i = 1;i <= n;i++) cout << dis[i] << ' ';
}

