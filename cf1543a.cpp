#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	int t;
	cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		if (a == b) {
			cout << "0 0\n";
			continue;
		}
		int x = abs(a - b);
		cout << x << ' ' << min(a % x, x - (a % x)) << '\n';
	}
}
