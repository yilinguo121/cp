#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int m, n;
	cin >> m >> n;
	int t[m][n];
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			cin >> t[i][j];
		}
	}
	int ans = -9999;
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			if (i == 0 and j == 0) continue;
			int l = -1e9, u = -1e9;
			if (i > 0) u = t[i - 1][j];
			if (j > 0) l = t[i][j - 1];
			t[i][j] += max(u, l);
		}
	}
	cout << t[m - 1][n - 1];
}
