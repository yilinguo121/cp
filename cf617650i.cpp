#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<vector<int>> v;
vector<int> in, out, p;
int now;
void dfs(int t) {
	in[t] = ++now;
	for (auto nt : v[t]) {
		if (in[nt]) continue;
		p[nt] = t;
		dfs(nt);
	}
	out[t] = now;
}
int main() {
	IO
	int n, m;
	cin >> n;
	v.resize(n + 1);
	p.resize(n + 1);
	in.resize(n + 1);
	out.resize(n + 1);
	for (int i = 0;i < n - 1;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		cout << ((in[x] <= in[y] and in[y] <= out[x]) or (in[p[x]] <= in[y] and in[y] <= out[p[x]]) ? 1 : 0) << '\n';
	}
}
