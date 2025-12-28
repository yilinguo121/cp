#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	unordered_map<int, int> mp;
	int ans = 0;
	for (int i = 1;i <= n;i++) {
		int b = i - v[i - 1];
		if (mp.count(b)) ans += mp[b];
		mp[i + v[i - 1]]++;
	}
	cout << ans;
}
