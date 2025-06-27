#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, m;
	cin >> n >> m;
	vector<vector<tuple<int, int, int>>> v(n + 1);
	while (m--) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		v[a].push_back({b, x, y});
		v[b].push_back({a, -x, -y});
	}
	queue<tuple<int, int, int>> q;
	vector<pair<int, int>> ans(n + 1, {INF, INF});
	vector<bool> cant(n + 1);
	q.push({1, 0, 0});
	ans[1] = {0, 0};
	while (!q.empty()) {
		auto [k, x, y] = q.front();
		q.pop();
		for (auto [nk, dx, dy] : v[k]) {
			if (ans[nk] == pair<int, int>{INF, INF}) {
				q.push({nk, x + dx, y + dy});
				ans[nk] = {x + dx, y + dy};
			}
			if (ans[nk] != pair<int, int>{x + dx, y + dy}) {
				cant[nk] = 1;
			}
		}
	}
	for (int i = 1;i <= n;i++) {
		if (ans[i] == pair<int, int>{INF, INF} or cant[i]) cout << "undecidable\n";
		else cout << ans[i].first << ' ' << ans[i].second << '\n';
	}
}
