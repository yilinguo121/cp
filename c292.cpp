#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int a[n][n];
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> a[i][j];
		}
	}
	int p = n / 2;
	int q = n / 2;
	cout << a[p][q];
	int x[4] = {0, -1, 0, 1};
	int y[4] = {-1, 0, 1, 0};
	int k = 1;
	while(1) {
		for (int i = 0;i < 2;i++) {
			for (int j = 0;j < k;j++) {
				if (p + x[m] < 0 or p + x[m] >= n or q + y[m] < 0 or q + y[m] >= n) {
					return 0;
				}
				p += x[m];
				q += y[m];
				cout << a[p][q];
			}
			m = (m + 1) % 4;
		}
		k++;
	}
}
