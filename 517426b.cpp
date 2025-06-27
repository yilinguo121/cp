#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n, q;
	cin >> n >> q;
	int c[n][n];
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> c[i][j];
		}
	}
	while (q--) {
		int a, b, d, ans = 0;
		cin >> a >> b >> d;
		a--;
		b--;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				if ((i - a) * (i - a) + (b - j) * (b - j) <= d * d) {
					ans += c[i][j];
				}
			}
		}
		cout << ans << '\n';
	}
}
