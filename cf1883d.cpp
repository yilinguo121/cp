#include <bits/stdc++.h>
using namespace std;
int main() {
	int q;
	cin >> q;
	multiset<int> x;
	multiset<int> y;
	while (q--) {
		char c;
		int l, r;
		cin >> c >> l >> r;
		if (c == '+') {
			x.insert(l);
			y.insert(r);
		}
		if (c == '-') {
			x.erase(x.find(l));
			y.erase(y.find(r));
		}
		if (x.size() <= 1) {
			cout << "NO\n";
			continue;
		}
		if (*y.begin() < *x.rbegin()) cout << "YES\n";
		else cout << "NO\n";
	}
}

