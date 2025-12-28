#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
map<pair<int, int>, bool> mp;
vector<bool> vis, a;
int ans;
vector<vector<int>> v;
void dfs(int t) {
	a[t] = 1;
	vis[t] = 1;
	for (auto nt : v[t]) {
		if (!vis[nt]) {
			dfs(nt);
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	v.resize(n + 1);
	vis.resize(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		mp[{a, b}] = 1;
		v[a].push_back(b);
	}
	for (int i = 1;i <= n;i++) {
		a.clear();
		a.resize(n + 1);
		vis.clear();
		vis.resize(n + 1);
		dfs(i);
		for (int j = 1;j <= n;j++) if (i != j and a[j] and !mp[{i, j}]) ans++;
	}
	cout << ans;
}

