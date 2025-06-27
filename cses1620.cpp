#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, t;
vector<int> v(200000);
bool check(int m) {
	int sum = 0;
	for (int i = 0;i < n;i++) {
		sum += m / v[i];
		if (sum >= t) return 1;
	}
	return sum >= t;
}
signed main() {
	cin >> n >> t;
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}
	int l = 0, r = 1e18, ans;
	while (l <= r) {
		int m = (l + r) / 2;
		if (check(m)) {
			r = m - 1;
			ans = m;
		}
		else {
			l = m + 1;
		}
	}
	cout << ans << '\n';
}

