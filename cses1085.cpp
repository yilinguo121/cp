#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
vector<int> v(200000);
int n, k;
int f(int m) {
	int cnt = 1, now = 0;
	for (int i = 0;i < n;i++) {
		now += v[i];
		if (now > m) {
			cnt++;
			now = v[i];
		}
	}
	return cnt;
}
signed main() {
	IO
	cin >> n >> k;
	int l = 0, r = 0, ans;
	for (int i = 0;i < n;i++) {
		cin >> v[i];
		l = max(l, v[i]);
		r += v[i];
	}
	while (l <= r) {
		int m = (l + r) / 2;
		if (f(m) > k) l = m + 1;
		else {
			r = m - 1;
			ans = m;
		}
	}
	cout << ans;
}

