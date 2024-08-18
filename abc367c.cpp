#include<bits/stdc++.h>
using namespace std;
int n, k;
int r[10];  // 儲存每個位置可選擇的最大數值範圍
vector<int> ans;  // 用來儲存當前生成的序列
				  //
// 遞迴函數 f：loc 代表當前處理到第幾個位置，sum 代表當前序列的總和
void f(int loc, int sum) {
	if (loc == n) {  // 當 loc 遍歷到序列的最後一個位置
		if (sum % k == 0) {  // 檢查序列的總和是否為 k 的倍數
			for (int i = 0; i < n; i++) {
				cout << ans[i] << ' ';  // 輸出當前生成的序列
			}
			cout << '\n';
		}
		return;  // 返回上一層遞迴
	}
	for (int i = 1; i <= r[loc]; i++) {  // 枚舉當前位置可以取的值
		ans.push_back(i);  // 將當前值加入序列
		f(loc + 1, sum + i);  // 遞迴處理下一個位置
		ans.pop_back();  // 回溯：移除當前值以便處理下一個可能的值
	}
}

int main() {
	cin >> n >> k;  // 讀取序列的長度 n 和目標倍數 k
	for (int i = 0; i < n; i++) {
		cin >> r[i];  // 讀取每個位置的最大可選值範圍
	}
	f(0, 0);  // 從位置 0 開始生成序列，初始總和為 0
}

