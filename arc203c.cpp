#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
const int mod = 998244353;
int c(int n, int k) {
	int a = 1, b = 1;
	for (int i = k, j = n;i > 0;i--, j--) {
		a = (a * (j % mod)) % mod;
	}
	for (int i = 1;i <= k;i++) {
		b = (b * (i % mod)) % mod;
	}
	return a / b;
}
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		cout << c(n + m - 2, n - 1) * c((n - 1) * (m - 1) - n - m + 2, k - n - m + 2) % mod << '\n';
	}
}

