#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	n--;  // 將 n 減 1，以便從 0 索引開始計數
	// 處理 n 為 0 的特殊情況
	if (n == 0) {
		cout << 0;  // 當 n 為 1 時，輸出 "0" 作為第 1 個好整數
		return 0;
	}
	string s = "";
	// 將 n 轉換為五進制並映射到對應的偶數字符，O(log₅(n))
	while(n) {
		char c = (n % 5) * 2 + '0';  // 將餘數轉換為對應的偶數字符，O(1)
		s = c + s;  // 插入到字串的前面，O(1)
		n = n / 5;  // 將 n 除以 5，準備處理下一位，O(1)
	}
	cout << s;  // 輸出最終生成的好整數
}

