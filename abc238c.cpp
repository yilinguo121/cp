#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int f(int k) {
	int m = k + 1;
	if (m % 2 == 0) m /= 2;
	else k /= 2;
	return (k % mod) * (m % mod) % mod;
}
signed main() {
	int n;
	cin >> n;
	int t = 1, ans = 0;
	while (10 * t <= n) {
		ans = ans % mod + f(t * 9);
		t *= 10;
	}
	cout << (ans % mod + f(n - t + 1) % mod) % mod << '\n';
}
