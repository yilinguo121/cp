#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int ans = 0;
	int mn = 1e6;
	int mx = 0;
	for (int i = 0;i < n;i++) {
		int t;
		cin >> t;
		mn = min(mn, t);
		mx = max(mx, t);
		ans = (ans ^ t);
	}
	for (int i = mn;i <= mx;i++) ans = (ans ^ i);
	cout << ans;
}

