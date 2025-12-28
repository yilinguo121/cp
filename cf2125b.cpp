#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int a, b, k;
		cin >> a >> b >> k;
		cout << ((a / gcd(a, b) <= k and b / gcd(a, b) <= k) ? 1 : 2) << '\n';
	}
}

