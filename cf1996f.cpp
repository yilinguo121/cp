#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
int f(int a1, int an, int d) {return (a1 + an) * ((an - a1) / d + 1) / 2;}
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n), b(n);
		for (int &x : a) cin >> x;
		for (int &x : b) cin >> x;
		int l = 1, r = *max_element(a.begin(), a.end()) + 1, ans = 0;
		while (l <= r) {
			int m = (l + r) / 2, cnt = 0, now = 0;
			for (int i = 0;i < n;i++) {
				if (a[i] < m) continue;
				cnt += 1 + (a[i] - m) / b[i];
				now += f(a[i] - (a[i] - m) / b[i] * b[i], a[i], b[i]);
			}
			if (cnt <= k) {
				r = m - 1;
				ans = now + (m - 1) * (k - cnt);
			}
			else l = m + 1;
		}
		cout << ans << '\n';
	}
}
