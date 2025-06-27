#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int x = 0, y = 0;
	int ans = 0;
	while (n--) {
		int t;
		char c;
		cin >> t >> c;
		if (c == 'L') {
			if (x != 0) {
				ans += abs(x - t);
			}
			x = t;
		}
		if (c == 'R') {
			if (y != 0) {
				ans += abs(y - t);
			}
			y = t;
		}
	}
	cout << ans;
}
