#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<vector<int>> v, up;
vector<int> deep;
void dfs(int t, int p) {
	up[t][0] = p;
	for (int i = 1;i < 20;i++) up[t][i] = up[up[t][i - 1]][i - 1];
	for (auto nt : v[t]) {
		if (nt == p) continue;
		deep[nt] = deep[t] + 1;
		dfs(nt, t);
	}
}
int lca(int a, int b) {
	if (deep[a] < deep[b]) swap(a, b);
	for (int i = 0;i < 20;i++) if (((deep[a] - deep[b]) >> i) & 1) a = up[a][i];
	if (a == b) return a;
	for (int i = 19;i >= 0;i--) if (up[a][i] != up[b][i]) a = up[a][i], b = up[b][i];
	return up[a][0];
}
int main() {
	IO
	int n, q;
	cin >> n >> q;
	v.resize(n + 1);
	deep.resize(n + 1);
	up.resize(n + 1, vector<int>(20));
	for (int i = 2, p;i <= n;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0);
	while (q--) {
		int a, b;
		cin >> a >> b;
		int x = lca(a, b);
		cout << deep[a] - deep[x] + deep[b] - deep[x] << '\n';
	}
}
