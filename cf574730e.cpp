#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<unsigned long long> st(n);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			char c;
			cin >> c;
			if (c == '1') st[i] |= (1ull << j);
		}
	}
	int ans = 0;
	for (int i = 0;i < n;i++) {
		for (int j = i + 1;j < n;j++) {
			if (__builtin_popcountll(st[i] & st[j]) >= k) ans++;
		}
	}
	cout << ans;
}

