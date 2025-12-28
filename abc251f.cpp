#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<vector<int>> v;
vector<pair<int, int>> t1, t2;
vector<bool> vis;
void dfs(int t) {
	vis[t] = 1;
	for (auto nt : v[t]) {
		if (vis[nt]) continue;
		t1.push_back({t, nt});
		dfs(nt);
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	v.resize(n + 1);
	vis.resize(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	vis.assign(n + 1, 0);
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		for (auto nt : v[t]) {
			if (vis[nt]) continue;
			q.push(nt);
			t2.push_back({t, nt});
			vis[nt] = 1;
		}
	}
	for (auto [x, y] : t1) cout << x << ' ' << y << '\n';
	for (auto [x, y] : t2) cout << x << ' ' << y << '\n';
}

