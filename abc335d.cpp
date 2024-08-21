#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // 初始化網格
    int a[n + 1][n + 1] = {};

    // 中心位置 (x, y)
    int x = (n + 1) / 2;
    int y = (n + 1) / 2;

    // 將 Takahashi 放在中心位置
    a[x][y] = n * n;

    // 定義方向向量 (下, 右, 上, 左)
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int j = 1;      // 方向移動步數
    int way = 3;    // 初始方向 (上)
    int i = n * n - 1; // 龍部件編號
    bool flag = 1;  // 控制迴圈

    // 遍歷網格，放置龍部件
    while (flag) {
        for (int k = 0; k < 2; k++) {  // 每兩個方向切換
            for (int t = 0; t < j; t++) {  // 按照步數移動
                // 檢查邊界條件
                if (x + dx[way] < 1 or y + dy[way] < 1 or x + dx[way] > n or y + dy[way] > n) {
                    flag = 0;
                    break;
                }

                // 移動並放置龍部件
                x += dx[way];
                y += dy[way];
                a[x][y] = i;
                i--;

                // 部件放置完成後退出
                if (i == 0) {
                    flag = 0;
                    break;
                }
            }
            if (!flag) break;

            // 方向切換
            way = (way + 1) % 4;
        }
        j++;  // 增加步數
    }

    // 輸出結果
    for (int k = 1; k <= n; k++) {
        for (int t = 1; t <= n; t++) {
            if (a[k][t] == n * n) {
                cout << "T ";  // 輸出 Takahashi
            } else {
                cout << a[k][t] << ' ';  // 輸出龍部件編號
            }
        }
        cout << '\n';
    }
}

