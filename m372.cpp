#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int n, m, ans = 0;
string s[500];
bool vis[500][500];
void bfs(int i, int j) {
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({i, j});
	vis[i][j] = 1;
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		cnt++;
		if (s[x][y] == 'X') {
			if (x + 1 < n and !vis[x + 1][y] and (s[x + 1][y] == 'I' or s[x + 1][y] == 'L' or s[x + 1][y] == 'J' or s[x + 1][y] == 'X')) {
				q.push({x + 1, y});
				vis[x + 1][y] = 1;
			}
			if (x - 1 >= 0 and !vis[x - 1][y] and (s[x - 1][y] == 'I' or s[x - 1][y] == '7' or s[x - 1][y] == 'F' or s[x - 1][y] == 'X')) {
				q.push({x - 1, y});
				vis[x - 1][y] = 1;
			}
			if (y + 1 < m and !vis[x][y + 1] and (s[x][y + 1] == 'H' or s[x][y + 1] == '7' or s[x][y + 1] == 'J' or s[x][y + 1] == 'X')) {
				q.push({x, y + 1});
				vis[x][y + 1] = 1;
			}
			if (y - 1 >= 0 and !vis[x][y - 1] and (s[x][y - 1] == 'H' or s[x][y - 1] == 'L' or s[x][y - 1] == 'F' or s[x][y - 1] == 'X')) {
				q.push({x, y - 1});
				vis[x][y - 1] = 1;
			}
		}
		if (s[x][y] == 'I') {
			if (x + 1 < n and !vis[x + 1][y] and (s[x + 1][y] == 'I' or s[x + 1][y] == 'L' or s[x + 1][y] == 'J' or s[x + 1][y] == 'X')) {
				q.push({x + 1, y});
				vis[x + 1][y] = 1;
			}
			if (x - 1 >= 0 and !vis[x - 1][y] and (s[x - 1][y] == 'I' or s[x - 1][y] == '7' or s[x - 1][y] == 'F' or s[x - 1][y] == 'X')) {
				q.push({x - 1, y});
				vis[x - 1][y] = 1;
			}
		}
		if (s[x][y] == 'H') {
			if (y + 1 < m and !vis[x][y + 1] and (s[x][y + 1] == 'H' or s[x][y + 1] == '7' or s[x][y + 1] == 'J' or s[x][y + 1] == 'X')) {
				q.push({x, y + 1});
				vis[x][y + 1] = 1;
			}
			if (y - 1 >= 0 and !vis[x][y - 1] and (s[x][y - 1] == 'H' or s[x][y - 1] == 'L' or s[x][y - 1] == 'F' or s[x][y - 1] == 'X')) {
				q.push({x, y - 1});
				vis[x][y - 1] = 1;
			}
		}
		if (s[x][y] == 'L') {
			if (x - 1 >= 0 and !vis[x - 1][y] and (s[x - 1][y] == 'I' or s[x - 1][y] == '7' or s[x - 1][y] == 'F' or s[x - 1][y] == 'X')) {
				q.push({x - 1, y});
				vis[x - 1][y] = 1;
			}
			if (y + 1 < m and !vis[x][y + 1] and (s[x][y + 1] == 'H' or s[x][y + 1] == '7' or s[x][y + 1] == 'J' or s[x][y + 1] == 'X')) {
				q.push({x, y + 1});
				vis[x][y + 1] = 1;
			}
		}
		if (s[x][y] == '7') {
			if (x + 1 < n and !vis[x + 1][y] and (s[x + 1][y] == 'I' or s[x + 1][y] == 'L' or s[x + 1][y] == 'J' or s[x + 1][y] == 'X')) {
				q.push({x + 1, y});
				vis[x + 1][y] = 1;
			}
			if (y - 1 >= 0 and !vis[x][y - 1] and (s[x][y - 1] == 'H' or s[x][y - 1] == 'L' or s[x][y - 1] == 'F' or s[x][y - 1] == 'X')) {
				q.push({x, y - 1});
				vis[x][y - 1] = 1;
			}
		}
		if (s[x][y] == 'F') {
			if (x + 1 < n and !vis[x + 1][y] and (s[x + 1][y] == 'I' or s[x + 1][y] == 'L' or s[x + 1][y] == 'J' or s[x + 1][y] == 'X')) {
				q.push({x + 1, y});
				vis[x + 1][y] = 1;
			}
			if (y + 1 < m and !vis[x][y + 1] and (s[x][y + 1] == 'H' or s[x][y + 1] == '7' or s[x][y + 1] == 'J' or s[x][y + 1] == 'X')) {
				q.push({x, y + 1});
				vis[x][y + 1] = 1;
			}
		}
		if (s[x][y] == 'J') {
			if (x - 1 >= 0 and !vis[x - 1][y] and (s[x - 1][y] == 'I' or s[x - 1][y] == '7' or s[x - 1][y] == 'F' or s[x - 1][y] == 'X')) {
				q.push({x - 1, y});
				vis[x - 1][y] = 1;
			}
			if (y - 1 >= 0 and !vis[x][y - 1] and (s[x][y - 1] == 'H' or s[x][y - 1] == 'L' or s[x][y - 1] == 'F' or s[x][y - 1] == 'X')) {
				q.push({x, y - 1});
				vis[x][y - 1] = 1;
			}
		}
	}
	ans = max(ans, cnt);
}
int main() {
	IO
	cin >> n >> m;
	for (int i = 0;i < n;i++) cin >> s[i];
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (!vis[i][j] and s[i][j] != '0') bfs(i, j);
		}
	}
	cout << ans;
}
