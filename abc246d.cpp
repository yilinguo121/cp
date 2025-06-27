#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int unsigned long long
int f(int i, int j) {
	return 1ll * i * i * i + i * i * j + i * j * j + j * j * j;
}
signed main() {
	int n;
	cin >> n;
	if (!n) {
		cout << 0;
		return 0;
	}
	int ans = 1e18;
	for (int i = 0, j = 1000000;i <= 1000000;i++) {
		while (j - 1 and f(i, j - 1) >= n) j--;
		ans = min(ans, f(i, j));
	}
	cout << ans;
}

