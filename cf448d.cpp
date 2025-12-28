#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n, m, k;
	cin >> n >> m >> k;
	int l = 1, r = n * m, ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2, cnt = 0;
		for (int i = 1;i <= n and cnt < k;i++) cnt += min(m, mid / i);
		if (cnt >= k) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans;
}
