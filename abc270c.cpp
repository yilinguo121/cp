#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int n, x, y;
vector<vector<int>> v;
vector<int> p;
bitset<200001> vis;
void dfs(int t) {
	vis[t] = 1;
	for (auto nt : v[t]) {
		if (vis[nt]) continue;
		p[nt] = t;
		if (nt == y) {
			vector<int> ans;
			while (nt != x) {
				ans.push_back(nt);
				nt = p[nt];
			}
			ans.push_back(x);
			reverse(ans.begin(), ans.end());
			for (auto k : ans) cout << k << ' ';
			exit(0);
		}
		dfs(nt);
	}
}
int main() {
	cin >> n >> x >> y;
	v.resize(n + 1);
	p.resize(n + 1);
	for (int i = 0;i < n - 1;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(x);
}

