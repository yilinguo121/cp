#include <bits/stdc++.h>
using namespace std;
string s;
char f(long long t, long long k) {
	if (!t) return s[k - 1];
	if (k == 1) return (s[0] - 'A' + t) % 3 + 'A';
	char c = f(t - 1, (k + 1) / 2);
	return (c - 'A' + 2 - (k & 1)) % 3 + 'A';
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s;
	int q;
	cin >> q;
	while (q--) {
		long long t, k;
		cin >> t >> k;
		cout << f(t, k) << '\n';
	}
}

