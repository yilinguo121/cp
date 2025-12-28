#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
bool vis[301][301][301];
int dp[301][301][301];
int dfs(int a, int b, int c) {
	if (!a and !b and c) return 0b001;
	if (!a and b and !c) return 0b010;
	if (a and !b and !c) return 0b100;
	if (vis[a][b][c]) return dp[a][b][c];
	int now = 0;
	vis[a][b][c] = 1;
	if (a and b) now |= dfs(a - 1, b - 1, c + 1);
	if (a and c) now |= dfs(a - 1, b + 1, c - 1);
	if (b and c) now |= dfs(a + 1, b - 1, c - 1);
	return dp[a][b][c] = now;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		dfs(a, b, c);
		cout << (bool)(dp[a][b][c] & 0b100) << ' ' << (bool)(dp[a][b][c] & 0b010) << ' ' << (bool)(dp[a][b][c] & 0b001) << '\n';
	}
}
