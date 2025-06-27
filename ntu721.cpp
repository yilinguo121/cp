#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	int start = INF, end = -1;
	for (auto &[x, y] : v) {
		cin >> x >> y;
		start = min(start, x);
		end = max(end, y);
	}
	sort(v.begin(), v.end());
	int last = start, pos = 0;
	int ans = 0;
	while (last <= end) {
		int l = -1, r = -1;
		while (pos < n and v[pos].first <= last) {
			if (v[pos].second >= r) {
				l = v[pos].first;
				r = v[pos].second;
			}
			pos++;
		}
		if (r < last) break;
		ans++;
		last = r + 1;
	}
	if (last < end) cout << -1;
	else cout << ans;
}
