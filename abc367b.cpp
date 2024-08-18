#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;  // 讀取輸入的浮點數字串
	int n = s.size();
	bool flag = 0;
	int t = 0, k = 0;
	// 第一遍掃描：檢查小數點後是否只有零
	for (int i = 0; i < n; i++) {
		if (s[i] == '.') {
			flag = 1;  // 標記找到小數點
		}
		else if (flag) {  // 處理小數點後的部分
			t++;  // 計算小數點後的數字個數
			if (s[i] == '0') k++;  // 計算小數點後的零的個數
		}
	}
	// 如果小數點後全是零，輸出小數點前的部分
	if (k == t) {
		for (int i = 0; i < n; i++) {
			if (s[i] == '.') return 0;  // 如果遇到小數點則結束輸出
			else cout << s[i];  // 否則輸出小數點前的部分
		}
	}
	// 第二遍掃描：移除小數點後的尾隨零
	flag = 1;
	string ans = "";
	for (int i = n - 1; i >= 0; i--) {
		if (flag) {
			if (s[i] == '0') continue;  // 跳過尾隨的零
			flag = 0;  // 一旦遇到不是零的數字，停止跳過
		}
		if (!flag) ans = ans + s[i];  // 將有效位數加入結果
	}
	reverse(ans.begin(), ans.end());  // 反轉結果字串
	cout << ans;  // 輸出處理後的結果
}

