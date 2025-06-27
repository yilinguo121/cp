#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int m, n, k, r, c;
	cin >> m >> n >> k >> r >> c;
	int a[m][n];
	for (int i = 0;i < m;i++) for (int j = 0;j < n;j++) cin >> a[i][j];
	int sum = 0, ans = 0;
	int way = 0;
	int x[4] = {0, 1, 0, -1};
	int y[4] = {1, 0, -1, 0};
	while (1) {
		if (a[r][c] == 0) break;
		sum += a[r][c];
		a[r][c]--;
		ans++;
		if (sum % k == 0) way = (way + 1) % 4;
		while (r + x[way] < 0 or c + y[way] < 0 or r + x[way] >= m or c + y[way] >= n or a[r + x[way]][c + y[way]] == -1) way = (way + 1) % 4;
		r += x[way];
		c += y[way];
	}
	cout << ans;
}

