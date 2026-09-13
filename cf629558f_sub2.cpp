#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (auto &[x, y] : v) cin >> x >> y;
	sort(v.begin(), v.end());
	int ans = 0;
	for (int j = 0;j < (1 << n);j++) {
		if (__builtin_popcount(j) <= ans) continue;
		int end = 0;
		bool flag = 1;
		for (int i = 0;i < n;i++) {
			if (!((1 << i) & j)) continue;
			if (v[i].first < end) {
				flag = 0;
				break;
			}
			end = v[i].second;
		}
		if (flag) ans = __builtin_popcount(j);
	}
	cout << ans;
}
