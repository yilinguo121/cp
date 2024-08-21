#include<bits/stdc++.h>
using namespace std;
#define int long long  // 使用 long long 處理大數
signed main() {
    int n, t, e[200005] = {};  // n: 數列長度, t: 操作數量, e[]: 存儲數列元素
    cin >> n >> t;
    map<int, int> m;  // 記錄數值出現次數
    m[0] = n;  // 初始所有元素為 0
    int cnt = 1;  // 記錄不同數值的數量
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        a--;  // 將索引轉為 0 基準
        if (--m[e[a]] == 0) cnt--;  // 更新前減少當前值的頻次
        e[a] += b;  // 更新元素值
        if (m[e[a]] == 0) cnt++;  // 更新後增加新值的頻次
        m[e[a]]++;
        cout << cnt << '\n';  // 輸出當前不同數值數量
    }
}

