#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
vector<vector<int>> v;
vector<int> ans;
vector<vector<bool>> vis;
int n, k;
void dfs(int t, int cnt) {
	vis[cnt % k][t] = 1;
	if (cnt % k == 0) ans[t] = cnt;
	for (auto nt : v[t]) {
		if (!vis[(cnt + 1) % k][nt]) dfs(nt, cnt + 1);
	}
}
signed main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		v.clear();
		v.resize(n + 1);
		ans.clear();
		ans.resize(n + 1, INF);
		vis.clear();
		vis.resize(k, vector<bool>(n + 1, 0));
		for (int i = 0;i < n - 1;i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		dfs(1, 0);
		for (int i = 2;i <= n;i++) cout << (ans[i] == INF ? -1 : ans[i] / k) << ' ';
		cout << '\n';
	}
}
