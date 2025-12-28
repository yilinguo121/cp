#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		int now[2] = {}, len[2] = {}, cnt[2] = {};
		for (auto x : s) {
			if (x == '0') {
				now[0]++;
				cnt[0]++;
				len[0] = max(len[0], now[0]);
				now[1] = 0;
			}
			else {
				now[1]++;
				cnt[1]++;
				len[1] = max(len[1], now[1]);
				now[0] = 0;
			}
		}
		cout << min(cnt[1] + 2 * (cnt[0] - len[0]), cnt[0] + 2 * (cnt[1] - len[1])) << '\n';
	}
}
