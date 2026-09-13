#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t, n, m, k;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		if (k == 1) cout << 1 << '\n';
		else if (k == 2 and m <= n) cout << m << '\n';
		else if (k == 2 and m > n) cout << n + m / n - 1 << '\n';
		else if (k == 3 and m > n) cout << m - n - m / n + 1 << '\n';
		else cout << 0 << '\n';
	}
}
