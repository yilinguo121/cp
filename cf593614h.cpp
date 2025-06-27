#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, s;
	cin >> n >> s;
	vector<int> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}
	int ans = 0;
	for (int i = 0, j = 0;i < n;i++) {
		while (j + 1 < n and v[i] + s >= v[j + 1]) j++;
		ans += j - i;
	}
	cout << ans;
}

