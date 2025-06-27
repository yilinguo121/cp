#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<vector<int>> v(100001);
vector<int> p(100001);
void dfs(int x, int pa) {
	for (auto nx : v[x]) {
		if (nx == pa) continue;
		if (p[nx]) {
			vector<int> ans;
			ans.push_back(nx);
			while (x != nx) {
				ans.push_back(x);
				x = p[x];
			}
			ans.push_back(nx);
			cout << ans.size() << '\n';
			for (auto k : ans) cout << k << ' ';
			exit(0);
		}
		p[nx] = x;
		dfs(nx, x);
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1;i <= n;i++) {
		if (!p[i]) {
			p[i] = i;
			dfs(i, 0);
		}
	}
	cout << "IMPOSSIBLE";
}
