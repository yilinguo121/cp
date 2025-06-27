#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n, m, p;
	cin >> n >> m >> p;
	vector<int> a(n), b(m), v(m + 1);
	for (int i = 0;i < n;i++) cin >> a[i];
	for (int i = 0;i < m;i++) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0;i < m;i++) v[i + 1] = v[i] + b[i];
	int ans = 0;
	for (int i = 0;i < n;i++) {
		int size = upper_bound(b.begin(), b.end(), p - a[i]) - b.begin();
		ans += v[size] + a[i] * size + (m - size) * p;
	}
	cout << ans;
}

