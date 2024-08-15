#include<bits/stdc++.h>
using namespace std;
int main() {
	int h, w, x, y, j;
	cin >> h >> w >> x >> y >> j;  // 讀取矩陣的高度h、寬度w、起始點座標(x, y)，以及新的顏色j
	int a[505][505] = {};  // 定義矩陣，存儲顏色值，O(H * W)
	bool vis[505][505] = {};  // 定義訪問標記矩陣，O(H * W)
	// 讀取矩陣的顏色值，O(H * W)
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> a[i][j];
		}
	}
	int color = a[x][y];  // 記錄起始點的原始顏色，O(1)
	queue<pair<int, int>> t;
	t.push({x, y});  // 將起始點加入隊列，O(1)
	vis[x][y] = 1;  // 標記起始點已訪問，O(1)
	a[x][y] = j;  // 將起始點顏色替換為新顏色，O(1)
	// 使用 BFS 遍歷相鄰的相同顏色區域，O(H * W)
	while (!t.empty()) {
		pair<int, int> pair;
		pair = t.front();
		t.pop();
		int x[4] = {-1, 0, 1, 0};  // 定義四個方向的移動，O(1)
		int y[4] = {0, 1, 0, -1};
		// 檢查每個相鄰格子，O(1)
		for (int i = 0; i < 4; i++) {
			int p = pair.first + x[i];
			int q = pair.second + y[i];
			// 確認新位置在矩陣範圍內，且未被訪問，且顏色與初始顏色相同，O(1)
			if (p < 1 or q < 1 or p > h or q > w) continue;
			if (a[p][q] != color) continue;
			if (vis[p][q]) continue;
			a[p][q] = j;  // 替換顏色，O(1)
			vis[p][q] = 1;  // 標記已訪問，O(1)
			t.push({p, q});  // 將新位置加入隊列，O(1)
		}
	}
	// 輸出更新後的矩陣，O(H * W)
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}
