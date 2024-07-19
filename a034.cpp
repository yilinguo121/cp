#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	while (cin >> n) {
		int ans = 0;
		for (int i = 31;i >= 0;i--) {
			if (n >= pow(2, i)) {
				n -= pow(2, i);
				ans += pow(10, i);
			}
		}
		cout << ans << '\n';
	}
}
