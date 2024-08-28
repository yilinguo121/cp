#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	int ans = 1;
	int a[n];
	for (int i = 0;i < n;i++) {
		cin >> a[i];
		ans += (a[i] / 5) * 3;
		a[i] = a[i] % 5;
		while (a[i] > 0) {
			if (ans % 3 == 0) a[i] -= 3;
			else a[i]--;
			ans++;
		}
	}
	ans--;
	cout << ans;
}

