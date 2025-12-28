#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, q;
	cin >> n >> q;
	map<int, int> mp;
	for (int i = 1;i <= n;i++) mp[i] = 1;
	while (q--) {
		int x, y;
		cin >> x >> y;
		auto up = mp.upper_bound(x), i = mp.begin();
		int ans = 0;
		while (i != up) {
			ans += i->second;
			i = mp.erase(i);
		}
		mp[y] += ans;
		cout << ans << '\n';
	}
}
