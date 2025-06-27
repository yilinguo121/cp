#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0;i < n;i++) cin >> v[i];
	for (int i = n - 2;i >= 0;i--) v[i] += v[i + 1];
	int ans = v[0];
	v[0] = -1e17;
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0;i < k - 1;i++) {
		ans += v[i];
	}
	cout << ans;
}

