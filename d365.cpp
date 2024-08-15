#include<bits/stdc++.h>
using namespace std;
// 比較函數，用來根據區域數量和字母順序對結果進行排序
bool cmp(pair<char, int> a, pair<char, int> b) {
	if (a.second != b.second) return a.second > b.second;  // 根據區域數量降序排序，O(1)
	return a.first < b.first;  // 如果數量相同，按字母順序排序，O(1)
}
int main() {
	int n;
	cin >> n;  // 讀取世界的數量，O(1)
	for (int i = 1; i <= n; i++) {
		cout << "World #" << i << '\n';  // 輸出世界編號，O(1)
		int h, w;
		cin >> h >> w;  // 讀取網格的高度h和寬度w，O(1)
		char c[h][w];  // 儲存網格的字母，O(H * W)
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> c[i][j];  // 讀取每一個網格中的字母，O(H * W)
			}
		}
		int cnt[26] = {};  // 用來計算每個字母區域的數量，O(26)
		bool vis[h][w] = {};  // 記錄每個位置是否已經被訪問過，O(H * W)
		// 遍歷網格中的每一個位置，O(H * W)
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (vis[i][j]) continue;  // 如果已經訪問過，跳過該位置，O(1)
				cnt[c[i][j] - 'a']++;  // 該字母區域的計數器加1，O(1)
				// 使用 BFS 遍歷相鄰的相同字母區域，O(H * W)
				queue<pair<int, int>> t;
				t.push({i, j});
				vis[i][j] = 1;
				while(!t.empty()) {
					pair<int, int> pair = t.front();
					t.pop();
					char f = c[pair.first][pair.second];
					// 定義四個方向的移動，O(1)
					int x[4] = {0, 1, 0, -1};
					int y[4] = {1, 0, -1, 0};
					for (int k = 0; k < 4; k++) {
						int p = pair.first + x[k];
						int q = pair.second + y[k];
						// 確認新位置在網格內且尚未被訪問，且字母相同，O(1)
						if (p < 0 or q < 0 or p >= h or q >= w) continue;
						if (vis[p][q]) continue;
						if (c[p][q] != f) continue;
						t.push({p, q});  // 將符合條件的新位置加入隊列，O(1)
						vis[p][q] = 1;  // 標記新位置已被訪問，O(1)
					}
				}
			}
		}
		vector<pair<char, int>> v;  // 儲存字母和對應的區域數量，O(26)
		for (int i = 0; i < 26; i++) {
			if (cnt[i] > 0) {
				v.push_back({i + 'a', cnt[i]});  // 添加字母和區域數量的配對，O(1)
			}
		}
		sort(v.begin(), v.end(), cmp);  // 根據規則對結果進行排序，O(26 log 26)
		for (int i = 0; i < v.size(); i++) {
			cout << v[i].first << ": " << v[i].second << '\n';  // 輸出排序後的結果，O(26)
		}
	}
}

