#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	string s;
	cin >> s;  // 讀取字串
	int t[26] = {};  // 用來儲存每個字母的出現次數
	int m = s.size();  // 字串的長度
	int ans = 0;  // 結果變數，用來計算不同字串的數量
	bool flag = 1;  // 標記變數，用來判斷是否有重複的字符
	// 計算每個字符的出現次數，時間複雜度為 O(m)
	for (int i = 0; i < m; i++) {
		int j = s[i] - 'a';  // 將字符映射到陣列索引
		t[j]++;  // 該字符出現次數加一
		if (t[j] > 1 and flag) {
			ans++;  // 如果有任意字符出現超過一次，則結果加1
			flag = 0;  // 只需要加一次，然後標記為已處理
		}
	}
	// 計算不同字符對之間的交換次數，時間複雜度為 O(26^2) = O(1)
	for (int i = 0; i < 26; i++) {
		for (int j = i + 1; j < 26; j++) {
			ans += t[i] * t[j];  // 兩個不同字符的出現次數相乘
		}
	}
	// 輸出結果
	cout << ans << '\n';
}

