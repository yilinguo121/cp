#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<tuple<int, int, int>> v(m);
	for (auto &[x, y, z] : v) cin >> x >> y >> z;
	while (q--) {
		int a, b, id;
		cin >> a >> b >> id;
		int now = 0, ans = 0;
		for (int i = a;i <= b;i++) {
			auto [l, r, add] = v[i - 1];
			if (l <= id and id <= r) now += add;
			ans = max(ans, now);
		}
		cout << ans << '\n';
	}
	
}

