#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int n;
vector<int> ans;
vector<vector<int>> vis;
void dfs(int i) {
	if (i == n) {
		for (int x = 0;x < n;x++) {
			for (int y = 0;y < n;y++) {
				cout << (ans[x] == y ? 'Q' : '*');
			}
			cout << '\n';
		}
		cout << '\n';
		return;
	}
	for (int j = 0;j < n;j++) {
		if (vis[0][j] or vis[1][i + j] or vis[2][i - j + n]) continue;
		vis[0][j] = vis[1][i + j] = vis[2][i - j + n] = 1;
		ans[i] = j;
		dfs(i + 1);
		vis[0][j] = vis[1][i + j] = vis[2][i - j + n] = 0;
	}
}
int main() {
	IO
	cin >> n;
	ans.resize(n);
	vis.resize(3, vector<int> (2 * n));
	dfs(0);
}
