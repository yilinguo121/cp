#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	int a[n + 1][n + 1];
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= i;j++) {
			cin >> a[i][j];
		}
	}
	int i = 1;
	for (int j = 1;j <= n;j++) {
		if (i >= j) i = a[i][j];
		else i = a[j][i];
	}
	cout << i;
}
