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
		int n;
		cin >> n;
		vector<int> v(n);
		int cnt = INF;
		for (int i = 0;i < n;i++) {
			cin >> v[i];
			cnt &= v[i];
		}
		if (cnt > 0) {
			cout << "1\n";
			continue;
		}
		int now = -1;
		int ans = 0;
		for (int i = 0;i < n;i++) {
			if (now == -1) now = v[i];
			else now &= v[i];
			if (now == cnt) {
				ans++;
				now = -1;
			}
		}
		cout << ans << '\n';
	}
}
