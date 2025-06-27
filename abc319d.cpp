#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
bool check (int m, vector<int> v) {
	int line = 0, now = 0;
	for (auto x : v) {
		if (x > m) return 0;
		if (!now) {
			line++;
			now = x;
		}
		else if (x + 1 + now <= m) now += x + 1;
		else {
			now = 0;
			line++;
			now = x;
		}
	}
	return line <= k;
}
signed main() {
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0;i < n;i++) cin >> v[i];
	int l = 1, r = 1e15, ans;
	while (l <= r) {
		int m = (l + r) / 2;
		if (check(m, v)) {
			ans = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	cout << ans;
}
