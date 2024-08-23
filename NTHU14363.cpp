#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> g[N], w(N), sub_w[N];  // g:鄰接列表, w:節點權重, sub_w:子樹權重

// 深度優先搜索 (DFS) 函數，構建子樹權重列表
void dfs(int u, int p) {
    sub_w[u].push_back(w[u]);  // 將當前節點的權重加入其子樹權重列表
    for (auto v : g[u]) {  // 遍歷當前節點的所有鄰接節點
        if (p == v) continue;  // 跳過父節點，防止回溯
        dfs(v, u);  // 遞歸處理子節點
        for (auto x : sub_w[v]) {  // 將子節點的子樹權重加入當前節點的子樹權重中
            sub_w[u].push_back(x);
        }
    }
    // 將子樹權重列表排序並反轉，以便從大到小排列
    sort(sub_w[u].begin(), sub_w[u].end());
    reverse(sub_w[u].begin(), sub_w[u].end());
    // 只保留前 20 大的權重
    if (sub_w[u].size() > 20) sub_w[u].resize(20);
}

int main() {
    int n, q;
    cin >> n >> q;

    // 讀取每個節點的權重
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    // 建立樹的鄰接列表
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // 從根節點（通常為 1）開始執行 DFS
    dfs(1, -1);

    // 處理每個查詢
    while (q--) {
        int v, k;
        cin >> v >> k;
        // 輸出節點 v 的子樹中第 k 大的權重
        cout << sub_w[v][k - 1] << '\n';
    }
}

