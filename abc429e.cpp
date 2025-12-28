#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	string s;
	cin >> s;
	s = " " + s;
	vector<vector<pair<int, int>>> dis(n + 1, vector<pair<int, int>>(2));
	queue<tuple<int, int, int>> q;
	for (int i = 1;i <= n;i++) {
		if (s[i] == 'S') {
			dis[i][0] = {i, 0};
			q.push({i, i, 0});
		}
	}
	while (!q.empty()) {
		auto [t, root, d] = q.front();
		q.pop();
		for (auto nt : v[t]) {
			if (!dis[nt][0].first) {
				dis[nt][0] = {root, d + 1};
				q.push({nt, root, d + 1});
			}
			else if (dis[nt][0].first != root and !dis[nt][1].first) {
				dis[nt][1] = {root, d + 1};
				q.push({nt, root, d + 1});
			}
		}
	}
	for (int i = 1;i <= n;i++) if (s[i] == 'D') cout << dis[i][0].second + dis[i][1].second << '\n';
}

