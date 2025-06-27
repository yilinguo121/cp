#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
signed main() {
	IO
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0;i < n;i++) {
		int l = i + 1, r = n - 1;
		while (l < r) {
			if (v[i] + v[l] + v[r] > x) r--;
			else if (v[i] + v[l] + v[r] < x) l++;
			else {
				if (v[l] == v[r]) {
					ans += (r - l) * (r - l + 1) / 2; //C(n, 2)
					break;
				}
				int x = 1, y = 1;
				while (v[l] == v[l + 1]) {
					x++;
					l++;
				}
				while (v[r] == v[r - 1]) {
					y++;
					r--;
				}
				ans += x * y;
				l++;
				r--;
			}
		}
	}
	cout << ans;
}
