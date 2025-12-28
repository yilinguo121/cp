#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n;
	cin >> n;
	vector<array<int, 3>> v(n);
	for (auto &[s, d, t] : v) cin >> s >> d >> t;
	sort(v.begin(), v.end());
	int ans = 0;
	do {
		int l = 0, r = 1000;
		while (l <= r) {
			int m = (l + r) / 2;
			int last = 0;
			bool can = 1;
			for (int i = 0;i < n;i++) {
				if (i) last += m;
				last = max(last, v[i][0]);
				if (last + v[i][2] > v[i][1]) {
					can = 0;
					break;
				}
				last += v[i][2];
			}
			if (can) ans = max(ans, m), l = m + 1;
			else r = m - 1;
		}
	} while(next_permutation(v.begin(), v.end()));
	cout << ans;
}
