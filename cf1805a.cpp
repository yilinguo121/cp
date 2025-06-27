#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 0;i < n;i++) {
			int a;
			cin >> a;
			ans = (ans ^ a);
		}
		if (ans != 0 and n % 2 == 0) {
			cout << -1 << '\n';
			continue;
		}
		cout << ans << '\n';
		continue;
	}
}

