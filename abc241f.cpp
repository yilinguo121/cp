#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
queue<pair<long long, long long>> q;
map<int, set<int>> h, w;
map<pair<int, int>, int> vis;
void f(int x, int y, int z) {
	if (!vis.count({x, y})) {
		vis[{x, y}] = z;
		q.push({x, y});
	}
}
int main() {
	int n, sx, sy, ex, ey;
	cin >> n >> n >> n >> sx >> sy >> ex >> ey;
	q.push({sx, sy});
	vis[{sx, sy}] = 0;
	while (n--) {
		int x, y;
		cin >> x >> y;
		h[y].insert(x);
		w[x].insert(y);
	}
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		if (x == ex and y == ey) {
			cout << vis[{x, y}];
			return 0;
		}
		auto ite = h[y].lower_bound(x);
		if (ite != h[y].end()) f(*ite - 1, y, vis[{x, y}] + 1);
		if (ite != h[y].begin()) f(*--ite + 1, y, vis[{x, y}] + 1);
		ite = w[x].lower_bound(y);
		if (ite != w[x].end()) f(x, *ite - 1, vis[{x, y}] + 1);
		if (ite != w[x].begin()) f(x, *--ite + 1, vis[{x, y}] + 1);
	}
	cout << -1;
}

