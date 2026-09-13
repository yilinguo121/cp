#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n + 1), pre(n + 1);
	for (int i = 1;i <= n;i++) {
		cin >> v[i];
		pre[i] = pre[i - 1] + v[i];
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << pre[r] - pre[l - 1] << '\n';
	}
}
