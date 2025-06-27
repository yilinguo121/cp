#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (auto &[x, y] : v) cin >> x >> y;
	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
		return a.second < b.second;
	});
	int l = 0, r = n - 1, cnt = 0, ans = 0;
	while (l <= r) {
		if (v[l].second <= cnt) {
			ans += v[l].first;
			cnt += v[l].first;
			l++;
		}
		else {
			int need = min(v[r].first, v[l].second - cnt);
			ans += 2 * need;
			cnt += need;
			v[r].first -= need;
			if (!v[r].first) r--;
		}
	}
	cout << ans;
}

