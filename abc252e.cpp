#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, m;
	cin >> n >> m;
	vector<vector<tuple<int, int, int>>> v(n + 1);
	for (int i = 1;i <= m;i++) {
		int a, b, w;
		cin >> a >> b >> w;
		v[a].push_back({b, w, i});
		v[b].push_back({a, w, i});
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	vector<int> p(n + 1);
	vector<int> dis(n + 1, INF);
	q.push({0, 1});
	dis[1] = 0;
	while (!q.empty()) {
		auto [d, t] = q.top();
		q.pop();
		if (d != dis[t]) continue;
		for (auto [nt, nd, i] : v[t]) {
			if (dis[nt] > d + nd) {
				dis[nt] = d + nd;
				q.push({dis[nt], nt});
				p[nt] = i;
			}
		}
	}
	for (int i = 2;i <= n;i++) cout << p[i] << ' ';
}

