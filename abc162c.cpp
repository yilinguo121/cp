#include <bits/stdc++.h>
using namespace std;
int main() {
	int k;
	cin >> k;
	int ans = 0;
	for (int i = 1;i <= k;i++) {
		for (int j = 1;j <= k;j++) {
			int t = gcd(i, j);
			for (int l = 1;l <= k;l++) {
				ans += gcd(t, l);
			}
		}
	}
	cout << ans;
}

