#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	int t, k;
	cin >> t;
	vector<int> a(n - 1);
	for (int i = 0;i < n - 1;i++) {
		cin >> k;
		a[i] = k - t;
		t = k;
	}
	if (n == 1) {
		cout << 1;
		return 0;
	}
	if (n == 2) {
		cout << 3;
		return 0;
	}
	int ans = 0;
	int m = 1;
	for (int i = 1;i < n - 1;i++) {
		if (a[i] == a[i - 1]) m++;
		else {
			ans += (m * (m + 1)) / 2;
			m = 1;
		}
	}
	ans += (m * (m + 1)) / 2;
	cout << ans + n;
}
