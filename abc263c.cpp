#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
set<vector<int>> ans;
vector<int> now;
int n, m;
void dfs(int id, int t) {
	if (id == n) {
		ans.insert(now);
		return;
	}
	for (int i = t + 1;i <= m;i++) {
		now.push_back(i);
		dfs(id + 1, i);
		now.pop_back();
	}
}
int main() {
	cin >> n >> m;
	dfs(0, 0);
	for (auto x : ans) {
		for (auto y : x) cout << y << ' ';
		cout << '\n';
	}
}
