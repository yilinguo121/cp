#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, k, l, r;
	cin >> n >> k >> l >> r;
	vector<int> v(n + 5);
	for (int i = 1;i <= n;i++) cin >> v[i];
	while (k--) {
		for (int i = 1;i <= n;i++) b[i] = (a[i - 1] + a[i + 1] + a[i] * (i == 1 or i == n ? n - 2 : n - 3));
	}
	for (int i = l;i <= r;i++) ans = (ans + b[i]) % 998244353;
	cout << ans;
}

