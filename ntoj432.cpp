#include<bits/stdc++.h>
using namespace std;
int n, m, f, doorx, doory;
bool vis[1005][1005] = {};  // 記錄地圖上每個點是否已經被訪問，空間複雜度: O(n * m)
bool fire[1005][1005] = {}; // 記錄地圖上每個點是否有火焰，空間複雜度: O(n * m)
bool can = 0;
int x[4] = {-1, 0, 1, 0}; // 四個方向的x軸變化量
int y[4] = {0, 1, 0, -1}; // 四個方向的y軸變化量

// 檢查新位置是否合法（在邊界內且無火焰），時間複雜度: O(f)
bool check(int nx, int ny) {
	if (nx < 1 or ny < 1 or nx > n or ny > m) {
		return 0;
	}
	for (int i = 0; i < f; i++) {  // 時間複雜度: O(f)
		if (fire[nx][ny]) {
			return 0;
		}
	}
	return 1;
}

// 使用深度優先搜索（DFS）進行探索，時間複雜度: O(n * m)
void dfs(int nx, int ny) {
	vis[nx][ny] = 1;
	if (nx == doorx and ny == doory) {
		can = 1;
	}
	for (int i = 0; i < 4; i++) { // 遍歷四個方向，時間複雜度: O(1)
		int newx = nx + x[i];
		int newy = ny + y[i];
		if (check(newx, newy) and !vis[newx][newy]) {
			dfs(newx, newy); // 遞迴遍歷地圖，時間複雜度: O(n * m)
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int nx, ny;
	cin >> n >> m;
	cin >> nx >> ny;
	cin >> doorx >> doory;
	cin >> f;
	for (int i = 0; i < f; i++) { // 記錄每個火焰的位置，時間複雜度: O(f)
		int a, b;
		cin >> a >> b;
		fire[a][b] = 1;
	}
	dfs(nx, ny); // 開始深度優先搜索，時間複雜度: O(n * m)
	if (can) {
		cout << "Cool!";
	} else {
		cout << "Harakiri!";
	}
}

/*
時間複雜度: O(n * m) 最壞情況下，每個節點都需要被訪問一次。
空間複雜度: O(n * m) 用來儲存地圖的訪問狀態和火焰位置。
*/

