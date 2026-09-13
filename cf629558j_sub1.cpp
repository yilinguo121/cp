#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> a(n);
	for (int i = 0;i < n;i++) cin >> a[i];
	unsigned long long h = 0;
	for (unsigned long long e = 1;e <= m;e++) {
		unsigned long long u, v, w;
		cin >> u >> v >> w;
		unsigned long long x = (e << 32) ^ w;
		h = h ^ x;
		h = (h << 1) | (h >> 63);
	}
	cout << (1 + (n - 1)) * (n - 1) / 2 << ' ' << h << '\n';
}

