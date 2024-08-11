#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int ma = 1e8; // 定義常數ma為10^8
	int n;
	cin >> n;
	vector<int> v(n);
	int sum = 0;
	// 讀取數字並計算總和
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	// 將數列排序
	sort(v.begin(), v.end());
	int ans = 0;
	int r = n - 1;
	// 計算每對數字之間的和
	for (int i = 0; i < n - 1; i++) {
		sum -= v[i]; // 更新sum減去當前的數字
		while (v[i] + v[r] >= ma and r >= i) r--; // 當兩數之和超過ma時，移動r指針
		r = max(r, i); // 確保r不會小於i
		ans += v[i] * (n - (i + 1)) + sum; // 更新答案
		ans = ans - (n - r - 1) * ma; // 如果超過了ma，減去多餘的部分
	}
	cout << ans << '\n';
}

