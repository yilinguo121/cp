#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int f(char c) {
	if (c >= 'a' and c <= 'z') return c - 'a' + 26;
	else if (c >= 'A' and c <= 'Z') return c - 'A';
	else if (c == '+') return 62;
	else if (c == '/') return 63;
	else return c - '0' + 52;
}
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> s(n + 1);
	for (int i = 1;i <= n;i++) {
		char c;
		cin >> c;
		s[i] = (s[i - 1] ^ (1ull << f(c)));
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << __builtin_popcountll((s[l - 1] ^ s[r])) << '\n';
	}
}

