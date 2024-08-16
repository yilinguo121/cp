#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
int main() {
	int n, q;
	cin >> n >> q;
	deque<pair<int, int>> location; // 使用雙端隊列來存儲每個部分的位置
	// O(N): 初始化所有部分的位置，初始設置為 (i, 0)
	for (int i = 1; i <= n; i++)
	    location.push_back({i, 0});
	// O(Q): 處理 Q 個查詢
	for (int i = 0; i < q; i++) {
		int type;
		cin >> type;
		if (type == 1) { // 移動頭部
			char c;
			cin >> c;
			int x = location[0].f; // 取出頭部的 x 座標
			int y = location[0].s; // 取出頭部的 y 座標
			// 根據指令更新頭部位置
			if (c == 'R') x++;
			if (c == 'L') x--;
			if (c == 'U') y++;
			if (c == 'D') y--;
			location.push_front({x, y}); // 將更新後的頭部位置加入到隊列的前端
			location.pop_back(); // 移除隊列的最後一個元素，模擬尾部的移動
			// O(1): 操作雙端隊列的 push_front 和 pop_back 為常數時間複雜度
		}
		else { // 查詢某部分的座標
			int p;
			cin >> p;
			p--; // 調整為 0 基礎索引
			// O(1): 輸出指定部分的座標
			cout << location[p].f << ' ' << location[p].s << '\n';
		}
	}
}
