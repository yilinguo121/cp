#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> st(n);
	map<long long, int> mp;
	int ans = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			char c;
			cin >> c;
			if (c == '1') st[i] |= (1ll << j);
		}
		ans += mp[((1 << m) - 1) ^ st[i]];
		mp[st[i]]++;
	}
	cout << ans;
}
