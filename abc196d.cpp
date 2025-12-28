#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int h, w, a, b, ans;
bool vis[20][20];
void dfs(int x, int y) {
	if (x >= h) {
		ans++;
		return;
	}
	if (y >= w) {
		dfs(x + 1, 0);
		return;
	}
	if (vis[x][y]) {
		dfs(x, y + 1);
		return;
	}
	vis[x][y] = 1;
	if (b) {
		b--;
		dfs(x, y + 1);
		b++;
	}
	if (a) {
		a--;
		if (y + 1 < w and !vis[x][y + 1]) {
			vis[x][y + 1] = 1;
			dfs(x, y + 2);
			vis[x][y + 1] = 0;
		}
		if (x + 1 < h and !vis[x + 1][y]) {
			vis[x + 1][y] = 1;
			dfs(x, y + 1);
			vis[x + 1][y] = 0;
		}
		a++;
	}
	vis[x][y] = 0;
}
int main() {
	cin >> h >> w >> a >> b;
	dfs(0, 0);
	cout << ans;
}
