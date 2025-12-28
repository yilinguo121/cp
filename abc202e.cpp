#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<vector<int>> v, deep;
vector<int> in, out;
int now = 0;
void dfs(int t, int d) {
	in[t] = ++now;
	deep[d].push_back(in[t]);
	for (auto nt : v[t]) {
		dfs(nt, d + 1);
	}
	out[t] = now;
}
int main() {
	int n;
	cin >> n;
	v.resize(n + 1);
	in.resize(n + 1);
	out.resize(n + 1);
	deep.resize(n + 1);
	for (int i = 2;i <= n;i++) {
		int x;
		cin >> x;
		v[x].push_back(i);
	}
	dfs(1, 0);
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		int l = lower_bound(deep[y].begin(), deep[y].end(), in[x]) - deep[y].begin();
		int r = --upper_bound(deep[y].begin(), deep[y].end(), out[x]) - deep[y].begin();
		cout << (r - l + 1) << '\n';
	}
}
