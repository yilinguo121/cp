#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, f; // 宣告變數 n 代表人數，f 代表最前面的人的位置
	cin >> n; // 讀取人數
	int a[n]; // 宣告陣列 a 用來存儲位置
	// 透過迴圈讀取輸入，並填充位置陣列，同時找出最前面的人
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (t == -1) f = i;
		// 如果 t 為 -1，代表這個人是隊伍的最前面
		else a[t - 1] = i;
		// 將站在 t 後面的人的位置存到陣列中
	}
	// 從前到後輸出隊伍中人的順序
	for (int i = 0; i < n; i++) {
		cout << f + 1 << ' '; // 輸出目前最前面人的號碼（1 起始）
		f = a[f]; // 更新 f 為隊伍中下一個人的位置
	}
}
// 複雜度分析：
// 此程式的時間複雜度為 O(n)，因為主要操作是兩個獨立的 for 迴圈，每個迴圈執行 n 次。
// 空間複雜度為 O(n)，因為陣列 a 使用了大小為 n 的額外空間來儲存每個人的位置。

