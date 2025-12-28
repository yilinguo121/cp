#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<pair<int, int>> v;
vector<int> t;
vector<bool> vis;
int ans, n, k;
void dfs(int now) {
	ans = max(ans, now);
	for (int i = 0;i < n;i++) {
		if (vis[i]) continue;
		if (v[i].first <= now and now <= v[i].second) vis[i] = 1, dfs(t[i]);
	}
}
int main() {
	IO
	int m;
	cin >> m;
	while (m--) {
		ans = 0;
		cin >> n >> k;
		v.resize(n);
		t.resize(n);
		vis.resize(n);
		for (int i = 0;i < n;i++) {
			cin >> v[i].first >> v[i].second >> t[i];
		}
		dfs(k);
		cout << ans << '\n';
	}
}

