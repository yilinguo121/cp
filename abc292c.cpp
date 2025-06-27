#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 1;i < n;i++) {
		for (int j = 1;j < n;j++) {
			if (i * j >= n) break;
			v[i * j]++;
		}
	}
	int ans = 0;
	for (int i = 1;i < n;i++) {
		ans += (v[i] * v[n - i]);
	}
	cout << ans;
}

