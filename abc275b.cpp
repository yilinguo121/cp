#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
signed main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	a %= mod;
	b %= mod;
	c %= mod;
	d %= mod;
	e %= mod;
	f %= mod;
	int ans = ((a * b) % mod * c) % mod - ((d * e) % mod * f) % mod;
	if (ans < 0) ans += mod;
	cout << ans % mod;
}
