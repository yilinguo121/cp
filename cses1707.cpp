#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int ans = INF;
vector<vector<int>> v(2501);
int vis[2501];
void bfs(int a, int b) {
	queue<int> q;
	q.push(a);
	vis[a] = 1;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (auto nt : v[t]) {
			if (t == a and nt == b) continue;
			if (vis[nt]) continue;
			vis[nt] = vis[t] + 1;
			q.push(nt);
			if (nt == b) return;
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> p;
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		p.push_back({a, b});
	}
	for (auto [x, y] : p) {
		memset(vis, 0, sizeof(vis));
		bfs(x, y);
		if (vis[y]) ans = min(ans, vis[y]);
	}
	cout << (ans > 1e9 ? -1 : ans);
}
