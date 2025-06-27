#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int l, n, m;
	cin >> l >> n >> m;
	vector<pair<int, int>> a(n + 1), b(m + 1);
	for (int i = 0;i < n;i++) cin >> a[i].first >> a[i].second;
	for (int j = 0;j < m;j++) cin >> b[j].first >> b[j].second;
	int pos_a = 0, pos_b = 0;
	long long ans = 0;
	while (pos_a < n or pos_b < m) {
		if (a[pos_a].first == b[pos_b].first) {
			int x = min(a[pos_a].second, b[pos_b].second);
			ans += x;
			a[pos_a].second -= x;
			b[pos_b].second -= x;
		}
		else {
			int x = min(a[pos_a].second, b[pos_b].second);
			a[pos_a].second -= x;
			b[pos_b].second -= x;
		}
		if (!a[pos_a].second) pos_a++;
		if (!b[pos_b].second) pos_b++;
	}
	cout << ans;
}

