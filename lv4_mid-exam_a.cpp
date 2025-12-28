#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<tuple<int, int, int, int>>> v(n + 1);
	while (m--) {
		int a, b, x, y, z;
		cin >> a >> b >> x >> y >> z;
		v[a].push_back({b, x, y, z});
		v[b].push_back({a, x, y, z});
	}
	priority_queue<pair<int, int>> q;
	vector<int> dis(n + 1, -1);
	dis[n] = k;
	q.push({k, n});
	while (!q.empty()) {
		auto [now, t] = q.top();
		q.pop();
		if (now < dis[t]) continue;
		for (auto [nt, a, b, c] : v[t]) {
			int l = 0, r = now, ans = -1;
			while (l <= r) {
				int mid = (l + r) / 2, v = (a + mid) % b;
				if (mid + min(v, b - v) + c <= now) ans = mid, l = mid + 1;
				else r = mid - 1;
			}
			if (ans > dis[nt]) {
				dis[nt] = ans;
				q.push({ans, nt});
			}
		}
	}
	cin >> k;
	while (k--) {
		int x;
		cin >> x;
		cout << dis[x] << '\n';
	}
}
