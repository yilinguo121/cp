#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	const int inf = 1e9;  // 定義一個大的負數來表示無效狀態
	cin >> n;  // 讀取遊戲回合數
	string s;
	cin >> s;  // 讀取青木的出招序列
	int dp[n + 1][3] = {};  // 定義動態規劃陣列，dp[i][j] 表示在第 i 回合選擇 j 時的最大勝場數
	char p[3] = {'R', 'P', 'S'};  // 對應的手勢
	// 動態規劃的過程，時間複雜度 O(n)
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			// 對於每一回合，高橋可以選擇不同的手勢，並且不能連續兩回合出同一手勢
			dp[i][j] = max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + (s[i - 1] == p[(j + 2) % 3]);
			// 如果高橋選擇的手勢會輸給青木，則這種情況設定為無效
			if (s[i - 1] == p[(j + 1) % 3]) {
				dp[i][j] = -inf;
			}
		}
	}
	// 輸出高橋可以贏得的最大場數
	cout << max({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
}

