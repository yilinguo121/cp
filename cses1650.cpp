#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i];
		if (i > 0) v[i] = (v[i] ^ v[i - 1]);
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		cout << (v[l - 1] ^ v[r]) << '\n';
	}
}

