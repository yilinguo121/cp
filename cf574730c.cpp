#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		long long n, k;
		cin >> n >> k;
		vector<int> v(k);
		for (int i = 0;i < k;i++) cin >> v[i];
		sort(v.begin(), v.end());
		long long ans = 0;
		do {
			long long x = n;
			for (int i = 0;i < k;i++) {
				x = x * (100ll - v[i]) / 100;
			}
			ans = max(ans, n - x);
		} while(next_permutation(v.begin(), v.end()));
		cout << ans << '\n';
	}
}

