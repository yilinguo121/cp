#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, m;
	cin >> n >> m;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	vector<int> a(n + 1), sz(n + 1);
	vector<vector<int>> v(n + 1);
	bitset<200001> vis;
	for (int i = 1;i <= n;i++) cin >> a[i];
	while (m--) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
		sz[x] += a[y];
		sz[y] += a[x];
	}
	for (int i = 1;i <= n;i++) q.push({sz[i], i});
	int cnt = 0, ans = 0;
	while (cnt < n) {
		auto [w, t] = q.top();
		q.pop();
		if (vis[t]) continue;
		vis[t] = 1;
		ans = max(w, ans);
		cnt++;
		for (auto nt : v[t]) {
			if (vis[nt]) continue;
			sz[nt] -= a[t];
			q.push({sz[nt], nt});
		}
	}
	cout << ans;
}
