#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<int> ans, cost;
vector<int> have;
vector<vector<pair<int, int>>> v;
vector<vector<int>> pos;
vector<vector<short>> vis;
int now = 0, now_key;
void dfs(int t) {
	vis[now_key][t] = now;
	ans[t] = min(ans[t], now);
	for (auto x : pos[t]) {
		have[x]++;
		now_key |= (1 << x);
	}
	for (auto [nt, w] : v[t]) {
		if ((w == -1 or have[w]) and now < vis[now_key][nt]) {
			dfs(nt);
		}
		else if (!have[w] and now + cost[w] < vis[now_key | (1 << w)][nt]) {
			now += cost[w];
			have[w]++;
			now_key |= (1 << w);
			dfs(nt);
			now -= cost[w];
			if (!--have[w]) now_key ^= (1 << w);
		}
	}
	for (auto x : pos[t]) if (!--have[x]) now_key ^= (1 << x);
}
int main() {
	IO
	int n, m, k;
	cin >> n >> m >> k;
	pos.resize(n);
	have.resize(k);
	ans.resize(n, INF);
	cost.resize(k);
	v.resize(n);
	vis.resize((1 << k), vector<short> (n, 6000));
	for (int i = 0;i < k;i++) {
		int a, b;
		cin >> a >> b;
		pos[a].push_back(i);
		cost[i] = b;
	}
	while (m--) {
		int a, b, w;
		cin >> a >> b >> w;
		v[a].push_back({b, w});
	}
	dfs(0);
	for (int i = 1;i < n;i++) cout << (ans[i] == INF ? -1 : ans[i]) << '\n';
}
