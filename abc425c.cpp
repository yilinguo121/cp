#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
#define int long long
signed main() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n + 1);
	for (int i = 1;i <= n;i++) {
		cin >> v[i];
		v[i] += v[i - 1];
	}
	int pos = 0;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int x;
			cin >> x;
			pos = (pos + x) % n;
		}
		else {
			int l, r;
			cin >> l >> r;
			l = (l - 1 + pos) % n + 1;
			r = (r - 1 + pos) % n + 1;
			if (l <= r) cout << v[r] - v[l - 1] << '\n';
			else cout << v[n] - v[l - 1] + v[r] << '\n';
		}
	}
}

