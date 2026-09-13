#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	string s = "youngturingprogram";
	int x;
	cin >> x;
	int ans = 0;
	vector<int> cnt(26);
	while (x > 0) {
		for (auto c : s) {
			if (cnt[c - 'a']) {
				x += (cnt[c - 'a'] * cnt[c - 'a'] * (c - 'a' + 1));
			}
			cnt[c - 'a']++;
			x -= (cnt[c - 'a'] * cnt[c - 'a'] * (c - 'a' + 1));
			if (x < 0) break;
		}
		if (x >= 0) ans++;
	}
	cout << ans;
}

