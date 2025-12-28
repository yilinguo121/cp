#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n), c(n), d(n);
		int x = 0, y = 0, cnt = 0;
		for (int i = 0;i < n;i++) {
			cin >> a[i] >> b[i] >> c[i] >> d[i];
			if (a[i] > c[i]) cnt += a[i] - c[i], a[i] = c[i];
			if (b[i] > d[i]) cnt += a[i] + (b[i] - d[i]);
		}
		cout << cnt << '\n';
	}
}

