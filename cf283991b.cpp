#include <bits/stdc++.h>
using namespace std;
int main() {
	//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> v(n + 1);
	for (int i = 1;i <= n;i++) cin >> v[i];
	while (k--) {
		int x;
		cin >> x;
		int l = 1, r = n, ans = 0;
		while (l <= r) {
			int m = (l + r) / 2;
			if (v[m] <= x) {
				l = m + 1;
				ans = m;
			}
			else {
				r = m - 1;
			}
		}
		cout << ans << '\n';
	}
}
