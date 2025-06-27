#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long ans = 1;
void f(long long a, long long b) {
	if (b <= 1) {
		ans = ((ans % mod) * (a % mod)) % mod;
		return;
	}
	if (b % 2) {
		ans = ((ans % mod) * (a % mod)) % mod;
	}
	a = ((a % mod) * (a % mod)) % mod;
	f(a, b / 2);
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		ans = 1;
		long long a, b;
		cin >> a >> b;
		if (!b) cout << 1 << '\n';
		else {
			f(a, b);
			cout << ans << '\n';
		}
	}
}

