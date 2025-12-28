#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n + 1), b(n + 1);
		for (int i = 1;i <= n;i++) cin >> a[i] >> b[i];
		int ans = 0, now = 0, side = 0;
		for (int i = 1;i <= n;i++) {
			if ((a[i] - now) % 2 == (side != b[i])) ans += a[i] - now;
			else ans += a[i] - now - 1;
			now = a[i];
			side = b[i];
		}
		cout << ans + m - now << '\n';
	}
}
