#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int n;
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		double x = 1;
		x /= 17;
		int ans = 0;
		while (n--) {
			x *= 10;
			ans += (int)x % 10;
		}
		cout << (int)x % 10 << ' ' << ans << '\n';
	}
}

