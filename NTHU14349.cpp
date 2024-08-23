#include<bits/stdc++.h>
using namespace std;
#define int long long  // 定義 int 為 long long 以處理大數

signed main() {
    int n;
    cin >> n;

    // 使用優先隊列(最小堆)來儲存數字，保證每次取出的都是當前最小的兩個數字
    priority_queue<int, vector<int>, greater<int>> v;

    // 將輸入的數字全部放入優先隊列
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v.push(t);
    }

    int ans = 0;  // 紀錄最小總加法成本

    // 每次取出最小的兩個數字，將它們相加，並將結果放回優先隊列
    while (v.size() > 1) {
        int sum = v.top();  // 取出第一個最小的數
        v.pop();
        sum += v.top();     // 取出第二個最小的數並相加
        v.pop();

        ans += sum;         // 更新總成本
        v.push(sum);        // 將和放回優先隊列
    }

    // 輸出最小總成本，並在結尾輸出換行符
    cout << ans << '\n';
}

