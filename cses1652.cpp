#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, q;
	cin >> n >> q;
	int a[n + 2][n + 2] = {};
	for (int i = 1;i <= n;i++) {
		string s;
		cin >> s;
		for (int j = 1;j <= n;j++) {
			char c = s[j - 1];
			if (c == '*') a[i][j]++;
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	}
	while (q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1] << '\n';
	}
}

