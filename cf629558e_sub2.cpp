#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n + 1);
	for (int i = 1;i <= n;i++) cin >> v[i];
	while (q--) {
		int l, r;
		cin >> l >> r;
		int sum = 0;
		for (int i = l;i <= r;i++) sum += v[i];
		cout << sum << '\n';
	}
}
