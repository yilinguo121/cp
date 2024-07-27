#include<bits/stdc++.h>
using namespace std;
char a[1000][1000];
void f(int k, int x, int y) {
	if (k == 0) {
		a[x][y] = '#';
		return;
	}
	int p[8] = {x, x, x, x + pow(3, k - 1), x + pow(3, k - 1), x + 2 * pow(3, k - 1), x + 2 * pow(3, k - 1), x + 2 * pow(3, k - 1)};
	int q[8] = {y, y + pow(3, k - 1), y + 2 * pow(3, k - 1), y, y + 2 * pow(3, k - 1), y, y + pow(3, k - 1), y + 2 * pow(3, k - 1)};
	for (int i = 0;i < 8;i++) {
		f(k - 1, p[i], q[i]);
	}
}
int main() {
	memset(a, '.', sizeof(a));
	int n;
	cin >> n;
	f(n, 1, 1);
	for (int i = 1;i <= pow(3, n);i++) {
		for (int j = 1;j <= pow(3, n);j++) {
			cout << a[i][j];
		}
		cout << '\n';
	}
}
