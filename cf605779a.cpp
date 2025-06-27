#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
int n, m, k;
bool f(int x) {
	return n * (m - m / (x + 1)) >= k;
}
signed main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		int l = 1, r = m, ans;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (f(mid)) {
				r = mid - 1;
				ans = mid;
			}
			else l = mid + 1;
		}
		cout << ans << '\n';
	}
}

