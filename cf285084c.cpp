#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	for (int &x : a) cin >> x;
	for (int &x : b) cin >> x;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int l = *min_element(a.begin(), a.end()) + *min_element(b.begin(), b.end()), r = *max_element(a.begin(), a.end()) + *max_element(b.begin(), b.end()), ans;
	while (l <= r) {
		int m = (l + r) / 2;
		int cnt = 0;
		for (int i = 0;i < n;i++) {
			if (a[i] >= m) break;
			cnt += upper_bound(b.begin(), b.end(), m - a[i]) - b.begin();
		}
		if (cnt >= k) {
			r = m - 1;
			ans = m;
		}
		else l = m + 1;
	}
	cout << ans;
}

