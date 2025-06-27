#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0;i < n;i++) cin >> v[i];
	int l = 0, r = *max_element(v.begin(), v.end()), ans = 0;
	while (l <= r) {
		int sum = 0, m = (l + r) / 2;
		for (auto x : v) sum += min(m, x);
		if (sum <= k) {
			ans = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	for (int i = 0;i < n;i++) {
		int t = min(v[i], ans);
		v[i] -= t;
		k -= t;
	}
	for (int i = 0;i < n;i++) {
		if (v[i] and k) {
			v[i]--;
			k--;
		}
		cout << v[i] << ' ';
	}
}

