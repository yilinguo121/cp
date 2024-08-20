#include<bits/stdc++.h>
using namespace std;
bool c[1005][1005], vis[1005][1005];  // c 用於儲存網格中的感測器位置，vis 用於追蹤已訪問過的感測器
int ans = 0, h, w;  // ans 用於儲存感測器群組的數量，h 和 w 分別是網格的行數和列數
// 這兩個陣列分別儲存 8 個方向的移動向量，對應於水平、垂直和對角線方向
int x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
// 檢查 (i, j) 位置是否有效
bool check(int i, int j) {
	if (i < 0 or j < 0 or i >= h or j >= w) return 0;  // 確保位置在網格內
	if (vis[i][j]) return 0;  // 如果該位置已經被訪問過，則返回 false
	if (!c[i][j]) return 0;  // 如果該位置沒有感測器，則返回 false
	return 1;  // 位置有效
}
// 深度優先搜索 (DFS) 函數，用於遍歷所有連接的感測器
void dfs(int i, int j) {
	vis[i][j] = 1;  // 標記當前位置為已訪問
	for (int k = 0; k < 8; k++) {  // 遍歷 8 個方向
		int newi = i + x[k];
		int newj = j + y[k];
		if (check(newi, newj)) dfs(newi, newj);  // 如果新位置有效，則遞迴進行 DFS
	}
}
int main() {
	cin >> h >> w;  // 讀取網格的高度和寬度
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char t;
			cin >> t;
			if (t == '.') c[i][j] = 0;  // 如果該位置是 '.'，則沒有感測器
			else c[i][j] = 1;  // 如果該位置是 '#'，則有感測器
		}
	}
	// 遍歷整個網格，找到所有未訪問的感測器，並使用 DFS 計算其所屬的群組
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (c[i][j] and !vis[i][j]) {  // 如果該位置有感測器且未被訪問過
				dfs(i, j);  // 開始 DFS
				ans++;  // 增加感測器群組的計數
			}
		}
	}
	cout << ans << '\n';  // 輸出感測器群組的總數
}

