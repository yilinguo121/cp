#include<bits/stdc++.h>
using namespace std;
#define int long long  // 定義 int 為 long long，確保處理大數時不會溢位
signed main() {
	int n, ans = 1e12;  // 讀入 n，並初始化 ans 為一個非常大的數值
	cin >> n;
	for (int i = 1; i * i <= n; i++) {  // 從 1 開始遍歷 i，直到 i^2 超過 n 為止
		int j = sqrt(n - (i * i));
		// 計算 j，使得 j^2 最接近 n - i^2
		ans = min(ans, abs(n - (i * i) - (j * j)));
		// 計算 |n - (i^2 + j^2)| 並更新最小值
		j++;
		// 檢查下一個可能的 j 值，因為 j^2 接近但可能有更小的差值
		ans = min(ans, abs(n - (i * i) - (j * j)));
		// 再次更新最小值
	}
	cout << ans;  // 輸出最小值，表示最接近 n 的 |x^2 + y^2 - n|
}

