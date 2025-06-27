#include <bits/stdc++.h>
using namespace std;
#define int long long
char f(int t, int x, int y) {
	if (!t) return 'R';
	if (x % 2 == 0 and y % 2 == 0) return 'B';
	return f(t - 1, (x + 1) / 2, (y + 1) / 2);
}
signed main() {
	int q;
	cin >> q;
	while (q--) {
		int t, x1, y1, x2, y2;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		for (int i = x1;i <= x2;i++) {
			for (int j = y1;j <= y2;j++) {
				cout << f(t, i, j);
			}
			cout << '\n';
		}
	}
}

