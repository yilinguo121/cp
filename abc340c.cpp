#include<bits/stdc++.h>
using namespace std;
#define int long long  // 使用 long long 來處理大數範圍的計算
signed main() {
	int n;
	cin >> n;  // 讀取輸入的數字 N
	int a = 1, b = 0;
	// 找到小於等於 n 的最大 2 的次方數 a，以及計算它是通過幾次乘 2 得到的
	while (1) {
		if (a * 2 <= n) {
			a = a * 2;  // 將 a 乘 2，找到最大的 2 的次方數
			b++;  // 計算 b，代表 2 乘了幾次
		}
		else break;  // 如果 a * 2 已經大於 n，則停止迴圈
	}
	// 這個 while 迴圈的時間複雜度為 O(log n)，因為每次迴圈都將 a 乘以 2，即指數增長。

	// 計算並輸出最終的操作成本：b * n 是主要部分，2 * (n - a) 是處理餘數的額外成本
	cout << b * n + 2 * (n - a);
	// 輸出結果的計算是 O(1) 的操作，總體時間複雜度由 while 迴圈主導，因此總體複雜度是 O(log n)。
}

