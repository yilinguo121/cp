#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	int k = 0;
	while (q--) {
		int t, x;
		cin >> t >> x;
		if (t == 1) {
			k += x;
			k %= n;
		}
		else {
			cout << s[(x - 1 - k + n) % n] << '\n';
		}
	}
}

