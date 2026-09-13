#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
int n;
vector<int> v, pre;
vector<vector<int>> vis;
int dfs(int l, int r) {
	if (l > r) return 0;
	if (vis[l][r] != -1) return vis[l][r];
	int mx = max(0ll, v[l]) + dfs(l + 1, r);
	for (int i = l + 1;i <= r;i++) mx = max(mx, (pre[i] - pre[l - 1]) + dfs(l + 1, i - 1) + dfs(i + 1, r));
	return vis[l][r] = mx;
}
signed main() {
	IO;
	cin >> n;
	v.resize(n + 1);
	pre.resize(n + 1);
	vis.resize(n + 1, vector<int>(n + 1, -1));
	for (int i = 1;i <= n;i++) {
		cin >> v[i];
		pre[i] = pre[i - 1] + v[i];
	}
	cout << dfs(1, n);
}
