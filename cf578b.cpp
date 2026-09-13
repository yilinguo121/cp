#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n, k, x;
	cin >> n >> k >> x;
	int t = 1;
	while (k--) t *= x;
	vector<int> v(n), pre(n), suf(n);
	for (auto &x : v) cin >> x;
	for (int i = 1;i < n;i++) pre[i] = pre[i - 1] | v[i - 1];
	for (int i = n - 2;i >= 0;i--) suf[i] |= suf[i + 1] | v[i + 1];
	int ans = 0;
	for (int i = 0;i < n;i++) ans = max(ans, pre[i] | (v[i] * t) | suf[i]);
	cout << ans;
}
