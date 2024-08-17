#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n; // 讀取食材的種類數量
	int q[15], a[15], b[15];
	for (int i = 1; i <= n; i++) {
		cin >> q[i];
	} // 時間複雜度: O(n)
	int x = 1000005;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; // 讀取每種食材製作 A 菜所需的量
		if (a[i]) x = min(x, q[i] / a[i]); // 計算能製作的最多 A 菜數量，避免除以零
	} // 時間複雜度: O(n)
	for (int i = 1; i <= n; i++) {
		cin >> b[i]; // 讀取每種食材製作 B 菜所需的量
	} // 時間複雜度: O(n)
	if (x == 1000005) x = 0; // 若未更新 x，則無法製作 A 菜，將 x 設為 0
	int ans = 0;
	for (int i = 0; i <= x; i++) {
		int y = 1000005;
		for (int j = 1; j <= n; j++) {
			if (b[j] > 0) y = min(y, (q[j] - (i * a[j])) / b[j]); // 計算製作 i 份 A 菜後最多能製作的 B 菜數量
		} // 時間複雜度: O(n)
		ans = max(ans, i + y); // 更新最大總份數
	} // 迴圈時間複雜度: O(x * n)
	cout << ans; // 輸出最終結果
}

