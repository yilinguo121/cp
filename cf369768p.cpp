#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0;i < n;i++) cin >> v[i];
	sort(v.begin(), v.end());
	int t = -(n - 1);
	int ans = 0;
	for (int i = 0;i < n;i++) {
		ans += v[i] * t;
		t += 2;
	}
	cout << ans;
}

