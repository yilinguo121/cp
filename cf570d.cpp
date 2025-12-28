#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<vector<int>> v, a, pre;
string s;
int now = 0;
vector<int> in, out, mp;
void dfs(int t, int deep) {
	in[t] = ++now;
	mp[now] = t;
	a[deep].push_back(in[t]);
	int mask = (1 << (s[t - 1] - 'a'));
	if (pre[deep].empty()) pre[deep].push_back(mask);
	else pre[deep].push_back(pre[deep].back() ^ mask);
	for (auto nt : v[t]) {
		dfs(nt, deep + 1);
	}
	out[t] = now;
}
int main() {
	IO	
	int n, m;
	cin >> n >> m;
	v.resize(n + 1);
	a.resize(n + 1);
	mp.resize(n + 1);
	in.resize(n + 1);
	out.resize(n + 1);
	pre.resize(n + 1);
	for (int i = 2;i <= n;i++) {
		int x;
		cin >> x;
		v[x].push_back(i);
	}
	cin >> s;
	dfs(1, 1);
	while (m--) {
		int u, h;
		cin >> u >> h;
		int l = lower_bound(a[h].begin(), a[h].end(), in[u]) - a[h].begin();
		int r = upper_bound(a[h].begin(), a[h].end(), out[u]) - a[h].begin() - 1;
		cout << (r < l or (!l and __builtin_popcount(pre[h][r]) <= 1) or (l > 0 and __builtin_popcount(pre[h][r] ^ pre[h][l - 1]) <= 1) ? "Yes\n" : "No\n");
	}
}

