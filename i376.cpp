#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[n][n] = {};
	for (int i = 0;i < n;i++) for (int j = 0;j < n;j++) cin >> a[i][j];
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			bool flag = 1;
			for (int k = 0;k < n;k++) {
				if (a[i][j] <= a[i][k] and k != j) flag = 0;
				if (a[i][j] >= a[k][j] and k != i) flag = 0;
				if (!flag) break;
			}
			if (flag) {
				cout << i << ' ' << j;
				return 0;
			}
		}
	}
	cout << "NO";
}

