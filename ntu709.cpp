#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int n, m, cnt;
vector<vector<vector<int>>> vis; //0存皇后 1存王宮
void dfs(int i, int x, int y) {
	if (i == n + m) {
		cnt++;
		return;
	}
	if (x) {
		for (int j = 0;j < n + m;j++) {
			if (vis[0][0][j] or vis[0][1][i + j] or vis[0][2][i - j + n + m - 1]) continue;
			if (vis[1][0][j] or vis[1][1][i + j] or vis[1][2][i - j + n + m - 1]) continue;
			vis[0][0][j]++;
			vis[0][1][i + j]++;
			vis[0][2][i - j + n + m - 1]++;
			dfs(i + 1, x - 1, y);
			vis[0][0][j]--;
			vis[0][1][i + j]--;
			vis[0][2][i - j + n + m - 1]--;
		}
	}
	if (y) {
		for (int j = 0;j < n + m;j++) {
			if (vis[0][0][j] or vis[0][1][i + j] or vis[0][2][i - j + n + m - 1]) continue;
			if (vis[1][0][j]) continue;
			vis[1][0][j]++;
			vis[1][1][i + j]++;
			vis[1][2][i - j + n + m - 1]++;
			dfs(i + 1, x, y - 1);
			vis[1][0][j]--;
			vis[1][1][i + j]--;
			vis[1][2][i - j + n + m - 1]--;
		}
	}
}
int main() {
	IO
	cin >> n >> m;
	vis.resize(2, vector<vector<int>> (3, vector<int> (2 * (n + m) - 1, 0)));
	dfs(0, n, m);
	cout << cnt;
}
