#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
signed main() {
	int n;
	cin >> n;
	char c[n][n] = {};
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> c[i][j];
		}
	}
	int a[n][n] = {};
	a[0][0] = 1;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (c[i][j] == '*') a[i][j] = 0;
			if (i == 0 and j == 0) continue;
			int u = 0, l = 0;
			if (i > 0) u = a[i - 1][j];
			if (j > 0) l = a[i][j - 1];
			a[i][j] = l + u;
			if (c[i][j] == '*') a[i][j] = 0;
			a[i][j] %= mod;
		}
	}
	cout << a[n - 1][n - 1];
}
