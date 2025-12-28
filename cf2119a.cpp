#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		int ans = 0;
		while (a != b) {
			if (a < b) {
				if (!(a % 2)) {
					ans += min(x, y);
					a++;
				}
				else {
					ans += x;
					a++;
				}
			}
			else {
				if (a % 2) {
					ans += y;
					a--;
				}
				else {
					ans = -1;
					break;
				}
			}
		}
		cout << ans << '\n';
	}
}

