#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	string s, t;
	cin >> s >> t;
	map<char, multiset<int>> mp;
	for (int i = 1;i <= s.size();i++) mp[s[i - 1]].insert(i);
	if (mp[t[0]].empty()) {
		cout << -1;
		return 0;
	}
	auto it = mp[t[0]].lower_bound(0);
	int ans = *it;
	for (int i = 1;i < t.size();i++) {
		if (mp[t[i]].empty()) {
			cout << -1;
			return 0;
		}
		auto nit = mp[t[i]].upper_bound(*it);
		if (nit == mp[t[i]].end()) {
			nit = mp[t[i]].lower_bound(0);
			ans += (s.size() - *it) + *nit;
			it = nit;
		}
		else {
			ans += (*nit - *it);
			it = nit;
		}
	}
	cout << ans;
}

