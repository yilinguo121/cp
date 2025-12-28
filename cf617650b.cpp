#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int n, q;
vector<vector<int>> v;
vector<vector<pair<int, int>>> a;
bitset<200001> vis;
vector<bool> ans;
void dfs(int t) {
	vis[t] = 1;
	for (auto [x, i] : a[t]) ans[i] = vis[x];
	for (auto nt : v[t]) dfs(nt);
	vis[t] = 0;
}
int main() {
	IO
	cin >> n;
	v.resize(n + 1);
	for (int i = 2;i <= n;i++) {
		int x;
		cin >> x;
		v[x].push_back(i);
	}
	cin >> q;
	ans.resize(q);
	a.resize(n + 1);
	for (int i = 0;i < q;i++) {
		int x, y;
		cin >> x >> y;
		a[y].push_back({x, i});
	}
	dfs(1);
	for (auto x : ans) cout << x << '\n';
}
