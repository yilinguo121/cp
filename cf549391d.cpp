#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			cin >> a[i][j];
			a[i][j] += a[i - 1][j];
		}
	}
	int ans = -1e18, now = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = i;j <= n;j++) {
			now = 0;
			for (int k = 1;k <= m;k++) {
				now += a[j][k] - a[i - 1][k];
				if (now) ans = max(ans, now);
				if (now < 0) now = 0;
			}
		}
	}
	cout << ans << '\n';
}
