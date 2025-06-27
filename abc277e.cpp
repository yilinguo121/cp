#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<vector<int>>> v(2, vector<vector<int>> (n + 1));
	while (m--) {
		int a, b, t;
		cin >> a >> b >> t;
		v[t][a].push_back(b);
		v[t][b].push_back(a);
	}
	map<int, bool> mp;
	map<pair<int, int>, bool> vis;
	while (k--) {
		int x;
		cin >> x;
		mp[x] = 1;
	}
	deque<tuple<int, int, int>> q;
	q.push_back({1, 0, 1});
	vis[{1, 1}] = 1;
	while (!q.empty()) {
		auto [x, l, t] = q.front();
		q.pop_front();
		if (x == n) {
			cout << l;
			return 0;
		}
		if (!vis.count({x, !t}) and mp.count(x)) {
			vis[{x, !t}] = 1;
			q.push_front({x, l, !t});
		}
		for (auto i : v[t][x]) {
			if (vis.count({i, t})) continue;
			vis[{i, t}] = 1;
			q.push_back({i, l + 1, t});
		}
	}
	cout << -1;
}
