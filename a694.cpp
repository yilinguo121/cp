#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	while (cin >> n >> m) {  // 不斷讀取 n 和 m，直到 EOF
		int s[505][505] = {};  // 定義前綴和矩陣，初始值為 0
		// 建立前綴和矩陣，複雜度 O(n^2)
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int t;
				cin >> t;  // 讀取矩陣元素
				// 計算前綴和
				s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + t;
			}
		}
		// 處理 m 個查詢，每個查詢的複雜度為 O(1)，總複雜度 O(m)
		for (int i = 0; i < m; i++) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;  // 讀取查詢區域
			// 計算子矩陣的總和並輸出結果
			cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] << '\n';
		}
	}
}

