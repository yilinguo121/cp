#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> v(n), cnt(n + 1);
		for (auto &x : v) {
			cin >> x;
			cnt[x]++;
		}
		bool flag = 0;
		for (auto x : v) {
			if (cnt[x] % k) {
				cout << 0 << '\n';
				flag = 1;
				break;
			}
		}
		if (flag) continue;
		vector<int> now(n + 1);
		int ans = 0;
		for (int i = 0, j = 0;i < n;i++) {
			now[v[i]]++;
			while (j < n and now[v[i]] > cnt[v[i]] / k) {
				now[v[j]]--;
				j++;
			}
			ans += (i - j + 1);
		}
		cout << ans << '\n';
	}
}
