#include<bits/stdc++.h>
using namespace std;
signed main() {
	int n;
	cin >> n;
	int s[105][105][105] = {};
	// 三重迴圈，計算 prefix sum, 複雜度 O(N^3)
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			for (int k = 1;k <= n;k++) {
				int t;
				cin >> t;
				s[i][j][k] = s[i - 1][j][k] + s[i][j - 1][k] + s[i][j][k - 1] - s[i - 1][j - 1][k] - s[i][j - 1][k - 1] - s[i - 1][j][k - 1] + s[i - 1][j - 1][k - 1] + t;
			}
		}
	}
	int q;
	cin >> q;
	// 處理每個查詢，複雜度 O(Q)
	for (int i = 0;i < q;i++) {
		int lx, rx, ly, ry, lz, rz;
		cin >> lx >> rx >> ly >> ry >> lz >> rz;
		// 計算查詢區間和，複雜度 O(1)
		int ans = s[rx][ry][rz] - s[lx - 1][ry][rz] - s[rx][ly - 1][rz] - s[rx][ry][lz - 1];
		ans = ans + s[lx-1][ly-1][rz] + s[rx][ly - 1][lz - 1] + s[lx - 1][ry][lz - 1];
		ans = ans - s[lx - 1][ly - 1][lz - 1];
		cout << ans << '\n';
	}
}

