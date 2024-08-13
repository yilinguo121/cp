#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, q;
	string s;
	cin >> n >> s >> q;  // 讀取字串長度、字串及操作次數
	char t[26] = {};  // 字符替換表，用來追蹤最終字符的映射
	// 初始化替換表，每個字符初始映射到自己
	for (int i = 0; i < 26; i++) {
		t[i] = i;
	}
	// 處理 q 次替換操作
	for (int i = 0; i < q; i++) {
		char a, b;
		cin >> a >> b;  // 讀取當前替換操作中的字符對 (a, b)
		// 更新替換表，將所有原來映射到 'a' 的字符改為映射到 'b'
		for (int j = 0; j < 26; j++) {
			if (t[j] == a - 'a') {
				t[j] = b - 'a';
			}
		}
	}
	// 根據最終的替換表更新字串
	for (int i = 0; i < n; i++) {
		s[i] = 'a' + t[s[i] - 'a'];
	}
	// 輸出最終結果
	cout << s;
}

