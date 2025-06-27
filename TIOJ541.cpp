#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	IO
	int n, s, t;
	cin >> n >> s >> t;
	map<pair<int, int>, int> team;
	map<int, vector<pair<int, int>>> mp;
	map<int, set<int>> r, c;
	queue<tuple<int, int, int>> q;
	pair<int, int> finish;
	map<pair<int, int>, bool> vis;
	for (int i = 1;i <= n;i++) {
		int x, y, e;
		cin >> x >> y >> e;
		team[{x, y}] = e;
		mp[e].push_back({x, y});
		r[x].insert(y);
		c[y].insert(x);
		if (i == s) {
			q.push({x, y, 0});
			vis[{x, y}] = 1;
		}
		if (i == t) finish = {x, y};
	}
	while (!q.empty()) {
		auto [x, y, l] = q.front();
		q.pop();
		for (auto [nx, ny] : mp[team[{x, y}]]) {
			if (abs(nx - x) == abs(ny - y) and !vis.count({nx, ny})) {
				q.push({nx, ny, l + 1});
				vis[{nx, ny}] = 1;
			}
		}
		if (vis.count(finish)) {
			cout << l + 1;
			return 0;
		}
		auto it = r[x].lower_bound(y);
		if (it != r[x].begin()) {
			--it;
			if (!vis.count({x, *it})) {
				q.push({x, *it, l + 1});
				vis[{x, *it}] = 1;
			}
		}
		it = r[x].upper_bound(y);
		if (it != r[x].end()) {
			if (!vis.count({x, *it})) {
				q.push({x, *it, l + 1});
				vis[{x, *it}] = 1;
			}
		}
		it = c[y].lower_bound(x);
		if (it != c[y].begin()) {
			--it;
			if (!vis.count({*it, y})) {
				q.push({*it, y, l + 1});
				vis[{*it, y}] = 1;
			}
		}
		it = c[y].upper_bound(x);
		if (it != c[y].end()) {
			if (!vis.count({*it, y})) {
				q.push({*it, y, l + 1});
				vis[{*it, y}] = 1;
			}
		}
		if (vis.count(finish)) {
			cout << l + 1;
			return 0;
		}
	}
	cout << -1;
}
