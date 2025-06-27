#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
#define int long long
signed main() {
	int a, e, s, y, n;
	cin >> n;
	long long ans = 0;
	for (e = 0;e <= n;e++) {
		for (a = 0;a <= n;a++) {
			if (e + a < n) continue;
			for (s = 0;s <= n;s++) {
				if (e + a - s * n > n) continue;
				for (y = 0;y <= n;y++) {
					if (e + a - s * y < n) break;
					if (e + a - s * y == n) ans++;
				}
			}
		}
	}
	cout << ans;
}
