#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
vector<vector<pair<int ,int>>> v;
vector<int> a;
signed main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		a.resize(n + 1);
		v.assign(n + 1, {});
		for (int i = 1;i <= n;i++) cin >> a[i];
		int sum = 0;
		for (int i = 0;i < n - 1;i++) {
			int x, y, z;
			cin >> x >> y >> z;
			v[x].push_back({y, z});
			v[y].push_back({x, z});
			if (a[x] != a[y]) sum += z;
		}
		while (q--) {
			int x, y;
			cin >> x >> y;
			for (auto [nx, w] : v[x]) {
				if (a[nx] == a[x]) sum += w;
				if (a[nx] == y) sum -= w;
			}
			a[x] = y;
			cout << sum << '\n';
		}
	}
}

