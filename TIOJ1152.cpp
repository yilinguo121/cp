#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v(10005);  // 用來儲存星球之間的連接關係，這裡預設最多有 10005 顆星球
int ma = 0;  // 用來儲存最長的空間跳躍距離
// 深度優先搜索（DFS）函數，s 是當前節點，p 是父節點，dis 是當前跳躍距離
// 複雜度：O(n)，每次 DFS 會遍歷一顆星球及其所有的相鄰星球，這個操作的時間複雜度與星球的數量 n 成正比
void dfs(int s, int p, int dis) {
	ma = max(ma, dis);  // 更新最大距離，這是 O(1) 的操作
	for (auto i : v[s]) {
		if (i == p) continue;  // 跳過父節點，避免迴圈，這是 O(1) 的操作
		dfs(i, s, dis + 1);  // 繼續搜索子節點，這是遞迴調用，複雜度仍然是 O(n)
	}
}
int main() {
	int n;
	cin >> n;  // 讀取星球的數量，這是 O(1) 的操作
	for (int i = 0; i < n; i++) {  // 複雜度：O(n)，需要遍歷所有星球
		int t;
		while (cin >> t) {  // 對於每顆星球，可能有多個相鄰星球，需要逐個讀取
			if (t == -1) {
				break;  // 當輸入為 -1 時，結束當前星球的相鄰星球讀取，這是 O(1) 的操作
			}
			v[t].push_back(i);  // 建立雙向邊，這是 O(1) 的操作
			v[i].push_back(t);  // 建立雙向邊，這是 O(1) 的操作
		}
	}
	// 複雜度：O(n^2)，我們對每顆星球都進行一次完整的 DFS 搜索，每次 DFS 的時間複雜度是 O(n)，因此總體是 O(n^2)
	for (int i = 0; i < n; i++) dfs(i, -1, 0);
	// 輸出最長的空間跳躍距離，這是 O(1) 的操作
	cout << ma << '\n';
}

