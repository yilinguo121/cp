#include<bits/stdc++.h>
using namespace std;
int a[5005][5005] = {};
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	while (n--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		a[x1][y1]++;
		a[x1][y2 + 1]--;
		a[x2 + 1][y1]--;
		a[x2 + 1][y2 + 1]++;
	}
	for (int i = 1;i <= 5000;i++) {
		for (int j = 1;j <= 5000;j++) {
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (x < 1 or y < 1 or x > 5000 or y > 5000) {
			cout << 0 << '\n';
			continue;
		}
		cout << a[x][y] << '\n';
	}
}
