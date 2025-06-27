#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	long long ans = 1;
	for (int i = 0;i < n;i++) {
		int t = v[i] - i;
		if (t <= 0) {
			cout << 0;
			return 0;
		}
		ans = ((ans % mod) * (t % mod)) % mod;
	}
	cout << ans;
}

