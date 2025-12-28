#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<vector<int>> v;
vector<int> ans;
vector<bool> vis;
int n, m, s, e;
bool flag = 0;
void dfs(int t) {
	if (flag) return;
	ans.push_back(t);
	vis[t] = 1;
	if (t == e) {
		for (auto x : ans) cout << x << ' ';
		cout << '\n';
		flag = 1;
		return;
	}
	for (auto nt : v[t]) {
		if (vis[nt]) continue;
		dfs(nt);
	}
	ans.pop_back();
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m >> s >> e;
		v.clear();
		v.resize(n + 1);
		vis.clear();
		vis.resize(n + 1);
		while (m--) {
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for (auto &x : v) sort(x.begin(), x.end());
		flag = 0;
		ans.clear();
		dfs(s);
	}
}

