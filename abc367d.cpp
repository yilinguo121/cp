#include<bits/stdc++.h>
using namespace std;
#define int long long  // 使用 long long 來處理大數運算
signed main() {
	int n, m;
	cin >> n >> m;  // 讀取休息區數量 n 和步數模數 m
	int a[2 * n + 5] = {}, ans = 0, cnt[m + 5] = {};  // 初始化累加和陣列 a 和計數陣列 cnt
	for (int i = 1; i <= n; i++) {
		cin >> a[i + 1];  // 讀取每段步數
		a[i + 1] += a[i];  // 計算前綴和
	} // 時間複雜度: O(n)

	for (int i = 2; i < n; i++) {
		a[n + i] = a[n + 1] + a[i];  // 擴展累加和陣列以處理環狀結構
	} // 時間複雜度: O(n)

	for (int i = 1; i <= n; i++) cnt[a[i] % m]++;  // 計算每個前綴和模 m 的結果
	// 時間複雜度: O(n)

	for (int i = 1; i <= n; i++) {
		ans += cnt[a[i] % m] - 1;  // 計算符合條件的 (s, t) 對數
		cnt[a[i] % m]--;  // 更新計數陣列以處理下一個位置
		cnt[a[n + i] % m]++;  // 更新計數陣列以包含擴展部分
	} // 時間複雜度: O(n)

	cout << ans;  // 輸出符合條件的對數總和
}

