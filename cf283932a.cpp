#include <bits/stdc++.h>
using namespace std;
int w, h, n;
bool check(long long m) {
	return (m / h) and (m / w) > (n - 1) / (m / h);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> w >> h >> n;
	long long l = 1, r = 1e18, ans = 0;
	while (l <= r) {
		long long m = (l + r) / 2;
		if (check(m)) {
			r = m - 1;
			ans = m;
		}
		else l = m + 1;
	}
	cout << ans;
}

