#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<vector<int>> v(n + 1);
	for (int i = 1;i <= n;i++) {
		int x;
		cin >> x;
		v[x].push_back(i); //紀錄x出現在的位置
	}
	int ans = 0;
	for (int i = 1;i <= n;i++) ans += (i / 2) * (n - i + 1);
	for (int i = 1;i <= n;i++) {
		int l = 0, r = v[i].size() - 1;
		while (l < r) {
			if (v[i][l] <= n - v[i][r] + 1) { //左邊剩餘長度較少
				ans -= (r - l) * v[i][l];
				l++;
			}
			else {
				ans -= (r - l) * (n - v[i][r] + 1);
				r--;
			}
		}
	}
	cout << ans;
}

