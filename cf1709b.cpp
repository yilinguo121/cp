#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n, m;
	cin >> n >> m;
	int a[n + 2] = {}, s[n + 1] = {}, b[n + 1] = {};
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		s[i] = s[i - 1];
		if (i > 1 and a[i] < a[i - 1]) s[i] += abs(a[i - 1] - a[i]);
	}
	a[n + 1] = 0;
	for (int i = n;i >= 1;i--) {
		b[i] = b[i + 1];
		if (i < n and a[i] < a[i + 1]) b[i] += abs(a[i + 1] - a[i]);
	}
	while (m--) {
		int l, r;
		cin >> l >> r;
		if (r > l) cout << abs(s[r] - s[l]) << '\n';
		else cout << abs(b[l] - b[r]) << '\n';
	}
}
