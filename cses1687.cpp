#include <bits/stdc++.h>
using namespace std;
const int maxN = 200001;  // 最大的員工數量
const int logK = 20;  // 根據題目限制，最多需要處理的層級數
int N, Q, x, k, p[maxN][logK];  // 員工數量、查詢數量、臨時變量 x 和 k，以及稀疏表 p
int main() {
    // 讀取員工數量和查詢數量
    cin >> N >> Q;
    // 讀取每個員工的直接上司
    for (int i = 2; i <= N; i++)
        cin >> p[i][0];

    // 構建稀疏表，用於快速查找上 k 層祖先
    for (int j = 1; j < logK; j++) {  // j 代表查找的 2^j 祖先
        for (int i = 1; i <= N; i++) {  // 遍歷所有員工
            p[i][j] = p[p[i][j - 1]][j - 1];  // 動態規劃填表
        }
    }
    // 處理查詢
    for (int q = 0; q < Q; q++) {
        cin >> x >> k;
        for (int i = 0; i < logK; i++) {
            if (k & (1 << i))  // 位運算來檢查 k 的第 i 位是否為 1
                x = p[x][i];
        }
        // 如果查詢結果是 0，則表示該層級的上司不存在，輸出 -1
        printf("%d\n", x ? x : -1);
    }
}

