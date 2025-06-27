#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ans = 0;
	for (int i = 0, j = 0;i < n and j < m;i++, j++) {
		if (a[i] >= 0 or b[j] >= 0) break;
		ans += a[i] * b[j];
	}
	for (int i = n - 1, j = m - 1;i >= 0 and j >= 0;i--, j--) {
		if (a[i] <= 0 or b[j] <= 0) break;
		ans += a[i] * b[j];
	}
	cout << ans;
}

