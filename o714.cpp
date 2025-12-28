#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int n, m, mod;
vector<bool> vis;
vector<int> dp;
map<int, vector<int>> v;
int f(int t) {
	if (vis[t]) return dp[t];
	vis[t] = 1;
	if (!t) return dp[t] = 1;
	int ans = 0;
	for (auto nt : v[t]) ans = (ans + f(nt)) % mod;
	return dp[t] = ans;
}
int main() {
	cin >> n >> m >> mod;
	vis.resize(m + 1);
	dp.resize(m + 1);
	vector<int> a(n), b(n);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;
	for (int i = 0;i < n;i++) v[b[i]].push_back(a[i]);
	cout << f(m);
}
