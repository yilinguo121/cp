#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v(205);  // 用於存儲圖的鄰接清單 (空間複雜度 O(N + M))
vector<int> vis(205);        // 用於標記節點是否已被訪問 (空間複雜度 O(N))
bool flag = 1;

void dfs(int x, int color) {
	vis[x] = color;
	for (auto i : v[x]) {
		if (vis[i] == vis[x]) {
			flag = 0;  // 如果鄰接節點有相同的顏色標記，則該圖不是二分圖
		}
		else if (vis[i] == 0){
			dfs(i, 3 - color);  // 標記鄰接節點為不同顏色
		}
	}
}

int main() {
	int n;
	while(cin >> n) {
		if (!n) break;
		int m;
		flag = 1;
		for (int i = 0;i <= 200;i++) {
			v[i].clear();
			vis[i] = 0;
		}
		cin >> m;
		for (int i = 0;i < m;i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);  // 構建鄰接清單 (空間複雜度 O(M))
			v[b].push_back(a);
		}
		dfs(1, 1);  // 開始 DFS 遍歷 (時間複雜度 O(N + M))
		if (!flag) {
			cout << "NOT BICOLORABLE." << '\n';
		}
		else{
			cout << "BICOLORABLE." << '\n';
		}
	}
}

