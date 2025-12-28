#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n;
	cin >> n;
	vector<int> v(n);
	int ans = 0;
	for (int i = 0;i < n;i++) {
		cin >> v[i];
		if (i) ans += max(0ll, v[i] - v[i - 1]);
	}
	ans += max(0ll, v[0] - v[n - 1]);
	cout << max(ans, *max_element(v.begin(), v.end()));
}
