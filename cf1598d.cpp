#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n], b[n], p[n + 1] = {}, q[n + 1] = {};
		for (int i = 0;i < n;i++) {
			cin >> a[i] >> b[i];
			p[a[i]]++;
			q[b[i]]++;
		}
		int ans = n * (n - 1) * (n - 2) / 6;
		for (int i = 0;i < n;i++) {
			ans -= (p[a[i]] - 1) * (q[b[i]] - 1);
		}
		cout << ans  << '\n';
	}
}
