#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);

    // 輸入數組元素
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // 對數組進行排序，以便後續使用二分搜索
    sort(v.begin(), v.end());

    // 處理每個查詢
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        // 使用 lower_bound 找到第一個 >= a 的位置
        auto lower = lower_bound(v.begin(), v.end(), a);

        // 使用 upper_bound 找到第一個 > b 的位置
        auto upper = upper_bound(v.begin(), v.end(), b);

        // 計算範圍內的元素個數
        int ans = upper - lower;

        // 輸出結果
        cout << ans << '\n';
    }
}

