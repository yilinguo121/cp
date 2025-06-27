#include <bits/stdc++.h>
using namespace std;
int main() {
	int m;
	cin >> m;
	while (m--) {
		int h1, m1, h2, m2, n;
		cin >> h1 >> m1 >> h2 >> m2 >> n;
		if (h2 * 60 + m2 - h1 * 60 - m1 >= n) cout << "Yes\n";
		else cout << "No\n";
	}
}

