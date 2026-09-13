#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n), suf(n + 1), a(n);
	for (auto &x : v) cin >> x;
	for (int i = n - 1;i >= 0;i--) suf[i] = suf[i + 1] + v[i];
	for (int i = 0;i < n;i++) a[i] = suf[i]/ v[i] + i;
	for (int x = 1, i = 0;x <= k;x++) {
		while (a[i] < x) i++;
		cout << suf[i] / (x - i) << '\n';
	}
}
