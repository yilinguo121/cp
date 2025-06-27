#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int m, n;
	cin >> m >> n;
	int t, k, r;
	cin >> t >> k >> r;
	vector<int> v(n + 1);
	while (t--) {
		int c;
		cin >> c;
		v[max(c - k + 1, 1ll)]++;
		v[min(c, n - k + 1) + 1]--;
	}
	int a = 0;
	int b = min(r, m - k + 1) - max(1ll, r - k + 1) + 1;
	for (int i = 1;i <= n;i++) {
		v[i] += v[i - 1];
		if (v[i] % 2) a += b;
	}
	if (k % 2) {
		cout << (n - k + 1) * (m - k + 1) - a;
	}
	else {
		cout << a;
	}

}
