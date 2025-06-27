#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		int ans;
		cin >> ans;
		n--;
		while (n--) {
			int x;
			cin >> x;
			ans = __gcd(x, ans);
		}
		cout << ans << '\n';
	}
}

