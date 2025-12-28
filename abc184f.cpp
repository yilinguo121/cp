#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n), a;
	for (int &x : v) cin >> x;
	for (int i = 0;i < (1 << (n / 2));i++) {
		int sum = 0;
		for (int j = 0;j < n / 2;j++) if ((1 << j) & i) sum += v[j];
		a.push_back(sum);
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0;i < (1 << n - (n / 2));i++) {
		int sum = 0;
		for (int j = 0;j < n - (n / 2);j++) if ((1 << j) & i) sum += v[j + n / 2];
		int x = *--upper_bound(a.begin(), a.end(), k - sum);
		ans = max(ans, (x + sum <= k ? x + sum : 0));
	}
	cout << ans;
}
