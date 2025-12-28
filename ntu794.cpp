#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = 1e18;
signed main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a = -INF, b = -INF, c = -INF;
		while (n--) {
			int x;
			cin >> x;
			tie(a, b, c) = make_tuple(max(a + x, x), max(a, b), max({b + x, c + x, c}));
		}
		cout << c << '\n';
	}
}
