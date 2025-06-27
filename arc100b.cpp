#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<int> a(n + 1, 0);
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	int ans = a[n];
	for (int i = 1, j = 2, k = 3;j <= n - 2;j++) {
		while (i + 1 < j and abs(a[i] - (a[j] - a[i])) > abs(a[i + 1] - (a[j] - a[i + 1]))) i++;
		while (k + 1 < n and abs((a[k] - a[j]) - (a[n] - a[k])) > abs((a[k + 1] - a[j]) - (a[n] - a[k + 1]))) k++;
		ans = min(ans, max({a[i], a[j] - a[i], a[k] - a[j], a[n] - a[k]}) - min({a[i], a[j] - a[i], a[k] - a[j], a[n] - a[k]}));
	}
	cout << ans;
}

