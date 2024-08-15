#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v(100005);  // 儲存家族樹的鄰接表，O(N)
int ma = 0, point;  // ma用來記錄最大距離，point用來記錄最遠節點，O(1)
int ans = 0;  // 用來儲存最終的血緣距離，O(1)
// 使用DFS遍歷樹結構，計算最大距離，O(N)
void dfs(int x, int p, int dis) {
	ans = max(ans, dis);  // 更新最遠血緣距離，O(1)
	if (dis > ma) {  // 如果當前距離大於最大距離，更新最遠點和最大距離，O(1)
		ma = dis;
		point = x;
	}
	for (auto i : v[x]) {  // 遍歷所有相鄰節點，O(deg(x))
		if (i != p) dfs(i, x, dis + 1);  // 遞迴遍歷，忽略來自父節點的邊，O(1)
	}
}
int main() {
	int n;
	cin >> n;  // 讀取家族成員的數量，O(1)
	for (int i = 0; i < n - 1; i++) {  // 建立家族樹的鄰接表，O(N)
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(point, -1, 0);  // 第二次DFS從最遠點出發，計算最遠血緣距離，O(N)
	cout << ans << '\n';  // 輸出最遠血緣距離，O(1)
}
