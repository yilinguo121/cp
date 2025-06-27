#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	map<int, int> mp;
	int cnt = 0, ans = 0;
	for (int i = 0, j = 0;i < n;i++) {
		cin >> v[i];
		mp[v[i]]++;
		if (mp[v[i]] == 1) cnt++;
		while (cnt > k) {
			mp[v[j]]--;
			if (!mp[v[j]]) cnt--;
			j++;
		}
		ans += i - j + 1;
	}
	cout << ans;
}

