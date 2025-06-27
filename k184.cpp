#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> v;
	int a[n], b[n];
	for (int i = 0;i < n;i++) {
		int r;
		cin >> a[i] >> b[i] >> r;
		v.push_back({2e19, r, i + 1});
	}
	for (int i = 0;i < m;i++) {
		int c, d;
		cin >> c >> d;
		for (int j = 0;j < n;j++) {
			get<0>(v[j]) = min(get<0>(v[j]), 1ll * (a[j] - c) * (a[j] - c) + (b[j] - d) * (b[j] - d));
		}
	}
	sort(v.begin(), v.end());
	for (auto x : v) {
		cout << get<2>(x) << '\n';
	}
}

