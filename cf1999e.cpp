#include <bits/stdc++.h>
using namespace std;
int main() {
	//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		long long ans = 0;
		int t = l;
		int k = 1;
		int y = 0;
		while (t > 0) {
			t /= 3;
			ans++;
			k *= 3;
			y++;
		}
		while (k <= r) {
			if (k / 3 <= l) ans += (k - l) * y;
			else ans += (k / 3 * 2) * y;
			y++;
			k *= 3;
		}
		if (k / 3 <= l) ans += (r - l + 1) * y;
		else ans += (r - k / 3 + 1) * y;
		cout << ans << '\n';
	}
}

