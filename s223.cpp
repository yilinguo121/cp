#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n + 1);
	vector<pair<int, int>> p(n + 1);
	for (int i = 1;i <= n;i++) cin >> p[i].first;
	for (int i = 1;i <= n;i++) cin >> p[i].second;
	int l = 0, r = 0, ans;
	sort(p.begin(), p.end());
	for (int i = 2;i <= n;i++) v[i] = (p[i].first - p[i - 1].first) + max(0ll, 2 * (p[i].second - p[i - 1].second)), r += v[i];
	while (l <= r) {
		int m = (l + r) / 2, sum = 0, cnt = 1;
		for (int i = 2;i <= n and cnt <= k;i++) {
			if (sum + v[i] <= m) sum += v[i];
			else sum = 0, cnt++;;
		}
		if (cnt <= k) r = m - 1, ans = m;
		else l = m + 1;
	}
	cout << ans << '\n';
}

