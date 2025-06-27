#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> v(n + 1);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (c == 1) {
			v[a].push_back({b, c});
			v[b].push_back({a, -c});
		}
		if (c == -1) {
			v[b].push_back({a, -c});
			v[a].push_back({b, c});
		}
		if (!c) {
			v[a].push_back({b, c});
			v[b].push_back({a, c});
		}
	}
	vector<int> vis(n + 1, -1);
	int ans = 0;
	for (int i = 1;i <= n;i++) {
		if (vis[i] >= 0) continue;
		queue<int> q;
		q.push(i);
		vis[i] = 0;
		vector<int> k;
		while (!q.empty()) {
			auto x = q.front();
			k.push_back(x);
			q.pop();
			for (auto [nx, type] : v[x]) {
				if (vis[nx] != -1) {
					if (type == 0 and vis[x] != vis[nx]) {
						cout << -1;
						return 0;
					}
					if (type == 1) {
						if (vis[nx] != (vis[x] + 1) % 3) {
							cout << -1;
							return 0;
						}
					}
					if (type == -1) {
						if (vis[x] != (vis[nx] + 1) % 3) {
							cout << -1;
							return 0;
						}
					}
				}
				else {
					if (!type) vis[nx] = vis[x];
					if (type == 1) vis[nx] = (vis[x] + 1) % 3;
					if (type == -1) vis[nx] = (vis[x] + 2) % 3;
					q.push(nx);
				}
			}
		}
		int cnt[3] = {};
		for (auto x : k) cnt[vis[x]]++;
		ans += min({cnt[0], cnt[1], cnt[2]});
	}
	cout << ans;
}

