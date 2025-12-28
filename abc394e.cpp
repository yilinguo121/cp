#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	char a[n][n];
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> a[i][j];
		}
	}
	queue<pair<int, int>> q;
	vector<vector<int>> ans(n, vector<int>(n, INF));
	for (int i = 0;i < n;i++) {
		ans[i][i] = 0;
		q.push({i, i});
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (i != j and a[i][j] != '-') {
				ans[i][j] = 1;
				q.push({i, j});
			}
		}
	}
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				if (a[i][x] != '-' and a[i][x] == a[y][j] and ans[i][j] == INF) {
					ans[i][j] = ans[x][y] + 2;
					q.push({i, j});
				}
			}
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << (ans[i][j] == INF ? -1 : ans[i][j]) << ' ';
		}
		cout << '\n';
	}
}

