#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
const int mod = 1'000'000'007;
int n, m, ans;
vector<vector<int>> v;
vector<bool> vis;
void dfs(int t, int start, int cnt) {
	for (auto nt : v[t]) {
		if (nt == start and cnt >= 2) ans = (ans + 1) % mod;
		else if (!vis[nt] and nt > start) {
			vis[nt] = 1;
			dfs(nt, start, cnt + 1);
			vis[nt] = 0;
		}
	}
}
int main() {
	IO
	cin >> n >> m;
	v.resize(n + 1);
	vis.resize(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1;i <= n;i++) {
		vis[i] = 1;
		for (auto ni : v[i]) {
			vis[ni] = 1;
			if (ni > i) dfs(ni, i, 1);
			vis[ni] = 0;
		}
		vis[i] = 0;
	}
	cout << ans / 2;
}
