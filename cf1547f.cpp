#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int g = 0;
		vector<int> v(2 * n);
		for (int i = 0;i < n;i++) cin >> v[i], g = gcd(g, v[i]);
		for (int i = 0;i < n;i++) v[i + n] = v[i] /= g;
		int lg = log(2 * n) + 1;
		vector<vector<int>> st(lg, vector<int>(2 * n));
		for (int i = 0;i < 2 * n;i++) st[0][i] = v[i];
		for (int k = 1;k < lg;k++) for (int i = 0;i + (1 << k) <= 2 * n;i++) st[k][i] = gcd(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
		int ans = 0;
		for (int i = 0;i < n;i++) {
			int l = 0, r = n - 1;
			while (l < r) {
				int m = (l + r) / 2, len = log2(m + 1);
				if (gcd(st[len][i], st[len][i + m - (1 << len) + 1]) == 1) r = m;
				else l = m + 1;
			}
			ans = max(ans, l);
		}
		cout << ans << '\n';
	}
}

