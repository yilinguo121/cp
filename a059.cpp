#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 1;i <= t;i++) {
		double a, b;
		cin >> a >> b;
		int ans = 0;
		for (int j = a;j <= b;j++) {
			if ((int)sqrt(j) == sqrt(j)) {
				ans += j;
			}
		}
		cout << "Case " << i << ": " << ans << '\n';
	}
}
