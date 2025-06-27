#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int ans;
	cin >> ans;
	n = n * 2 - 2;
	while (n--) {
		int t;
		cin >> t;
		ans = (ans ^ t);
	}
	cout << ans;
}

