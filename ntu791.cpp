#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n, m, q;
	cin >> n >> m >> q;
	int a[n + 5][m + 5] = {};
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			cin >> a[i][j];
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	}
	while (q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x2++;
		y2++;
		cout << a[x2][y2] - a[x1][y2] - a[x2][y1] + a[x1][y1] << '\n';
	}
}
