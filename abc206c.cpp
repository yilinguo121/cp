#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0;i < n;i++) cin >> v[i];
	sort(v.begin(), v.end());
	int ans = (n - 1) * n / 2;
	int t = 1;
	for (int i = 1;i < n;i++) {
		if (v[i] == v[i - 1]) t++;
		else {
			if (t >= 2) {
				ans -= (t - 1) * (t) / 2;
			}
			t = 1;
		}
	}
	if (t >= 2) {
		ans -= (t - 1) * (t) / 2;
	}
	cout << ans;
}

