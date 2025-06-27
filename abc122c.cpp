#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	s = " " + s;
	int a[n + 1] = {};
	for (int i = 1;i <= n;i++) {
		if (s[i - 1] == 'A' and s[i] == 'C') a[i]++;
		a[i] += a[i - 1];
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << a[r] - a[l] << '\n';
	}
}
