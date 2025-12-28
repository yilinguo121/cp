#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<vector<int>> v;
bitset<200001> vis;
int ans;
void dfs(int t) {
	ans++;
	if (ans >= 1000000) {
		cout << 1000000;
		exit(0);
	}
	for (auto nt : v[t]) {
		vis[t] = 1;
		if (!vis[nt]) dfs(nt);
		vis[t] = 0;
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	v.resize(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	cout << ans;
}

