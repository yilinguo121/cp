#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n, d, k;
		cin >> n >> d >> k;
		int x = lcm(d, n) / d;
		k--;
		cout << (k % x) * d % n + k / x;
		cout << '\n';
	}
}
