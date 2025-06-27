#include<bits/stdc++.h>
using namespace std;
const long long MAX = 1e18;
int main() {
	int n;
	cin >> n;
	long long ans = 1;
	bool flag = 1;
	while (n--) {
		long long t;
		cin >> t;
		if (t == 0) {
			ans = 0;
			cout << 0;
			return 0;
		}
		if (flag) {
			if (ans > MAX / t) flag = 0;
			else ans *= t;
		}
	}
	if (flag) cout << ans;
	else cout << -1;
}
