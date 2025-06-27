#include <bits/stdc++.h>
using namespace std;
int main() {
	int k;
	cin >> k;
	while (k--) {
		int l, r;
		cin >> l >> r;
		vector<bool> v(r - l + 1);
		for (long long i = 2;i * i <= r;i++) {
			int t = r / i * i;
			while (t >= l and t > i) {
				v[t - l] = 1;
				t -= i;
			}
		}
		int ans = 0;
		for (auto x : v) {
			if (!x) ans++;
		}
		cout << ans << '\n';
	}
}

