#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b, c, d;
	while (cin >> a >> b >> c >> d) {
		int ans = c + d;
		a = max(0, a - (64 - 27) * c);
		if (b % 8) ans++;
		ans += b / 8;
		b %= 8;
		a = max(0, a - (64 - 8) * b);
		if (a % 64) ans++;
		ans += a / 64;
		cout << ans << '\n';
	}
}

