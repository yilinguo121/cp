#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
const long long mod = 1000000007;
int f(int x, int y) {
	if (y == 0) return 1;
	int a = f(x, y / 2);
	return (y & 1 ? a * a % mod * x % mod : a * a % mod);
}
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int y;
		cin >> y;
		cout << f(4, y - 1) << '\n';
	}
}

