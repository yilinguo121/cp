#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<vector<int>> v;
bitset<200001> vis;
void dfs(int t) {
	vis[t] = 1;
	cout << t << ' ';
	for (auto nt : v[t]) {
		if (vis[nt]) continue;
		dfs(nt);
		cout << t << ' ';
	}
}
int main() {
	int n;
	cin >> n;
	v.resize(n + 1);
	for (int i = 0;i < n - 1;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (auto &x : v) sort(x.begin(), x.end());
	dfs(1);
}

