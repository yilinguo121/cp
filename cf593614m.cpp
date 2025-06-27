#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int unsigned long long
signed main() {
	IO
	int n;
	cin >> n;
	vector<vector<int>> v(n + 1);
	for (int i = 1;i <= n;i++) {
		int x;
		cin >> x;
		while (x--) {
			int y;
			cin >> y;
			v[i].push_back(y);
		}
	}
	int ans = 0;
	for (int i = 1;i <= n;i++) {
		ans += 1ll * v[i].size() * (v[i].size() - 1) / 2;
		sort(v[i].begin(), v[i].end());
	}
	cout << ans << '\n';
	int cnt = 0;
	for (int x = 1;x <= n;x++) {
		for (auto y : v[x]) {
			for (auto z : v[y]) {
				if (z <= x) continue;
				cout << x << ' ' << y << ' ' << z << '\n';
				cnt++;
				if (cnt == 100000) return 0;
			}
		}
	}
}

