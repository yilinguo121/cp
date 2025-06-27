#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int l, r;
	cin >> l >> r;
	if (r - l >= 2019) {
		cout << 0;
		return 0;
	}
	int ans = 10000;
	for (int i = l;i <= r;i++) {
		for (int j = i + 1;j <= r;j++) {
			ans = min(ans, (i * j) % 2019);
		}
	}
	cout << ans;
}

