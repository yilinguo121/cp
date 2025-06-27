#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	int t, ans = 0;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		x %= (a + b);
		if (x >= a) ans += a + b - x;
	}
	cout << ans;
}

