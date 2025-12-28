#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
const int mod = 998244353;
vector<vector<int>> v;
map<tuple<int, int, int>, int> dp;
map<tuple<int, int, int>, bool> vis;
int n, m, k;
int dfs(int t, int ls, int ft) {
	if (vis[{t, ls, ft}]) return dp[{t, ls, ft}];
	int now = 0;
	for (int i = lower_bound(v[t].begin(), v[t].end(), ls - k) - v[t].begin();i < m;i++) {
		int x = v[t][i];
		if (abs(x - ls) <= k) {
			if (t == 1) now += (abs(x - ft) <= k);
			else now += dfs(t - 1, x, ft);
			now %= mod;
		}
		else break;
	}
	vis[{t, ls, ft}] = 1;
	return dp[{t, ls, ft}] = now;
}
int main() {
	IO
	cin >> n >> m >> k;
	v.resize(n, vector<int>(m));
	for (auto &y : v) {
		for (auto &x : y) cin >> x;
		sort(y.begin(), y.end());
	}
	v.push_back(v[0]);
	int ans = 0;
	for (int i = 0;i < m;i++) {
		ans += dfs(n - 1, v[n][i], v[n][i]);
		ans %= mod;
	}
	cout << ans;
}

