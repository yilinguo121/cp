#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for (auto &x : a) cin >> x;
		for (auto &x : b) cin >> x;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		long long ans = 0;
		int al = 0, bl = 0, ar = n - 1, br = m - 1;
		while (al <= ar) {
			if (abs(a[al] - b[br]) > abs(a[ar] - b[bl])) {
				ans += abs(a[al] - b[br]);
				al++;
				br--;
			}
			else {
				ans += abs(a[ar] - b[bl]);
				ar--;
				bl++;
			}
		}
		cout << ans << '\n';
	}
}
