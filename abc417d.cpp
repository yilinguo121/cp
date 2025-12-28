#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
#define int long long
struct t {
	int p;
	int a;
	int b;
};
signed main() {
	int n;
	cin >> n;
	vector<t> v(n);
	int sum = 0;
	for (auto &[x, y, z] : v) {
		cin >> x >> y >> z;
		sum += z;
	}
	int q;
	cin >> q;
	unordered_map<int, int> mp;
	while (q--) {
		int x;
		cin >> x;
		if (x > n * 500) {
			cout << x - sum << '\n';
			continue;
		}
		int k = x;
		if (mp.count(x)) cout << mp[x] << '\n';
		else {
			for (auto [p, a, b] : v) {
				if (p >= x) x += a;
				else x = max(0ll, x - b);
			}
			cout << x << '\n';
			mp[k] = x;
		}
	}
}
