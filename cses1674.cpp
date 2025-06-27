#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<vector<int>> v(200001);
vector<int> vis(200001);
void dfs(int t) {
	for (auto nt : v[t]) {
		dfs(nt);
		vis[t] += vis[nt] + 1;
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 2;i <= n;i++) {
		int x;
		cin >> x;
		v[x].push_back(i);
	}
	dfs(1);
	for (int i = 1;i <= n;i++) cout << vis[i] << ' ';
}
