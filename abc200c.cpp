#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	int a[200] = {};
	for (int i = 0;i < n;i++) {
		int t;
		cin >> t;
		a[t % 200]++;
	}
	int ans = 0;
	for (int i = 0;i < 200;i++) {
		int k = a[i];
		ans += (k * (k - 1) / 2);
	}
	cout << ans;
}
