#include<bits/stdc++.h>
using namespace std;
int main() {
	int h, w, n;
	cin >> h >> w >> n;  // 讀取網格的高度h，寬度w，和航行指令的長度n
	string s[h], t;
	cin >> t;  // 讀取航行指令字符串t
	for (int i = 0; i < h; i++) {
		cin >> s[i];  // 讀取網格的每一行，代表每個位置是陸地或海洋
	}
	// 定義四個方向的字符和對應的坐標移動
	char c[4] = {'L', 'R', 'U', 'D'};
	int x[4] = {0, 0, -1, 1};  // 對應於橫向的移動（L: 左, R: 右）
	int y[4] = {-1, 1, 0, 0};  // 對應於縱向的移動（U: 上, D: 下）
	int ans = 0;  // 計算符合條件的格子數量
	// 遍歷網格中的每個位置
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			bool flag = 1;  // 初始設置為可以航行
			if (s[i][j] == '#') flag = 0;  // 如果初始位置是海洋，則無法航行
			int ni = i, nj = j;  // 記錄當前位置
			if (flag) {
				// 模擬航行的每一步，O(N)
				for (int k = 0; k < n; k++) {
					if (flag) {
						for (int l = 0; l < 4; l++) {
							if (t[k] == c[l]) {  // 找到當前指令對應的方向
								ni += x[l];  // 更新位置
								nj += y[l];
								if (s[ni][nj] == '#') flag = 0;  // 如果移動到海洋格子，則停止
								break;  // 一次只處理一個方向，跳出內層循環
							}
						}
					}
				}
			}
			if (flag) ans++;  // 如果可以成功航行，則計算該格子
		}
	}
	cout << ans << '\n';  // 輸出結果
}
