#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0;i < n;i++) cin >> v[i];
		int ans = 0;
		int l = 0, r = n - 1;
		int l_total = 0, r_total = 0;
		while (l <= r) {
			if (l_total > r_total) {
				r_total += v[r];
				r--;
			}
			else {
				l_total += v[l];
				l++;
			}
			if (l_total == r_total) ans = max(ans, l + n - r - 1);
		}
		cout << ans << '\n';
	}
}

