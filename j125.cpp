#include<bits/stdc++.h>
using namespace std;
int n;
int a[300][300];
int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};
int check(int t) {
	int dis[300][300];
	memset(dis, -1, sizeof(dis));
	dis[0][0] = 0;
	queue<pair<int, int>> q;
	q.push({0, 0});
	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		for (int k = 0;k < 4;k++) {
			int ni = i + x[k];
			int nj = j + y[k];
			if (dis[ni][nj] == -1 and ni >= 0 and nj >= 0 and ni < n and nj < n) {
				if (abs(a[i][j] - a[ni][nj]) <= t) {
					dis[ni][nj] = dis[i][j] + 1;
					q.push({ni, nj});
				}
			}
		}
	}
	return dis[n - 1][n - 1];
}
int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> a[i][j];
		}
	}
	int r = 1000000,l = -1;
	int ans;
	while (r > l + 1) {
		int mid = (l + r) / 2;
		int t = check(mid);
		if (t == -1) l = mid;
		else {
			r = mid;
			ans = t;
		}
	}
	cout << r << '\n' << ans;

}
