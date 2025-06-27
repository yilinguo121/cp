#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n, q;
	cin >> n >> q;
	vector<pair<int, int>> v(n);
	int ans = 0;
	for (int i = 0;i < n;i++) {
		cin >> v[i].first;
		ans += v[i].first;
	}
	pair<int, int> last = {0, 0};
	for (int i = 1;i <= q;i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int k, x;
			cin >> k >> x;
			k--;
			if (last.second > v[k].second) {
				ans = ans - last.first + x;
				v[k].second = i;
				v[k].first = x;
			}
			else {
				ans = ans - v[k].first + x;
				v[k].second = i;
				v[k].first = x;
			}
		}
		else {
			int x;
			cin >> x;
			ans = x * n;
			last.first = x;
			last.second = i;
		}
		cout << ans << '\n';
	}
}

