#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, q, mod;
	cin >> n >> q >> mod;
	vector<int> v(n), a(q);
	vector<bool> vis(n);
	for (auto &x : v) cin >> x;
	for (auto &x : a) {
		cin >> x;
		vis[--x] = 1;
	}
	vector<int> ans(q);
	ans[--q] = 1;
	for (int i = 0;i < n;i++) ans[q] *= (vis[i] ? 1 : v[i]) % mod;
	while (q--) ans[q] = ans[q + 1] * v[a[q + 1]] % mod;
	for (auto x : ans) cout << x << '\n';
}

