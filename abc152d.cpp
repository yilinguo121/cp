#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int a[10][10] = {};
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		a[to_string(i)[0] - '0'][i % 10]++;
	}
	int ans = 0;
	for (int i = 1;i <= 9;i++) {
		for (int j = 0;j < 10;j++) {
			ans += a[i][j] *  a[j][i];
		}
	}
	cout << ans << '\n';
}
