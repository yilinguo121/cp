#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k, type;
	cin >> n >> k >> type;
	vector<pair<int, int>> v;
	for (int i = 0;i < n;i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({a, 1});
		v.push_back({b, -1});
	}
	sort(v.begin(), v.end());
	int m = v.size();
	int now = 1, sum = 0, ans = 0;
	bool open = 0;
	for (int i = 1;i < m;i++) {
		if (v[i].first == v[i - 1].first and v[i].second + v[i - 1].second == 0) {
			now -= v[i - 1].second;
			if (now >= k) {
				if (!open) {
					sum++;
					open = 1;
				}
			}
			continue;
		}
		if (now >= k) {
			ans += v[i].first - v[i - 1].first;
			if (!open) {
				sum++;
				open = 1;
			}
		}
		else {
			if (open) {
				sum++;
				open = 0;
			}
		}
		now += v[i].second;
	}
	if (now < k) {
		if (open) {
			sum++;
			open = 0;
		}
	}
	cout << ans;
	if (type) cout << ' ' << sum;
}
