#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	int ans = 0;
	int a[n + 1] = {};
	int t = 0;
	bool flag = 0;
	for (int i = 0;i < n;i++) cin >> a[i];
	for (int i = 0;i < n;i++) {
		if (flag) {
			if (a[i] == 9) {
				if (i > 0 and !a[i - 1]) t--;
				if (i < n - 1 and !a[i + 1]) t--;
			}
			if (!a[i]) t++;
			if (a[i] == 1) {
				if (t > 0) ans += t;
				t = 0;
			}
		}
		if (a[i] == 1) flag = 1;
	}
	cout << ans << '\n';
}
