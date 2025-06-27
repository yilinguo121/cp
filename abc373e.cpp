#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
signed main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n + 1), b(n + 1), sum(n + 1);
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		b[i] = a[i];
		k -= a[i];
	}
	if (n == m) {
		while (n--) cout << "0 ";
		return 0;
	}
	sort(b.begin(), b.end());
	for (int i = 1;i <= n;i++) sum[i] = sum[i - 1] + b[i];
	for (int i = 1;i <= n;i++) {
		int l = 0, r = k + 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			int pos = lower_bound(b.begin(), b.end(), a[i] + mid + 1) - b.begin() - 1;
			if (pos < n - m or (a[i] + mid + 1) * (pos - (n - m)) - (sum[pos] - sum[n - m - 1] - max(a[i], b[n - m])) <= k - mid) l = mid + 1;
			else r = mid - 1;
		}
		if (l > k) cout << "-1 ";
		else cout << l << ' ';
	}
}
