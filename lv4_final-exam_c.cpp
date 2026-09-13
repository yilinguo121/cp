#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
int get(int a, int n, int m) {
	int ans = 1;
	a %= m;
	for (;n > 0;a = a * a % m, n = (n >> 1)) if (n & 1) ans = ans * a % m;
	return ans;
}
signed main() {
	int t, type;
	cin >> t >> type;
	while (t--) {
		int n, x, m;
		cin >> n >> x >> m;
		x %= m;
		if (x == 1) cout << n % m << '\n';
		else cout << x * (get(x, n, m) - 1 + m) % m * get(x - 1, m - 2, m) % m << '\n';
	}
}

