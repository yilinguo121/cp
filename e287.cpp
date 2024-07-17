#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int a[105][105];
	int t = 1000005;
	int x, y;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> a[i][j];
			if (a[i][j] < t) {
				t = a[i][j];
				x = i;
				y = j;
			}
		}
	}
	int ans = a[x][y];
	a[x][y] = -1;
	while(1) {
		int k = 0;
		int nx, ny;
		int u = 1000005;
		if (x + 1 >= n or a[x + 1][y] == -1){
			k++;
		}else {
			if (a[x + 1][y] < u) {
				u = a[x + 1][y];
				nx = x + 1;
				ny = y;
			}
		}
		if (x - 1 < 0 or a[x - 1][y] == -1){
			k++;
		}else {
			if (a[x - 1][y] < u) {
				u = a[x - 1][y];
				nx = x - 1;
				ny = y;
			}
		}
		if (y + 1 >= m or a[x][y + 1] == -1){
			k++;
		}else {
			if (a[x][y + 1] < u) {
				u = a[x][y + 1];
				nx = x;
				ny = y + 1;
			}
		}
		if (y - 1 < 0 or a[x][y - 1] == -1){
			k++;
		}else {
			if (a[x][y - 1] < u) {
				u = a[x][y - 1];
				nx = x;
				ny = y - 1;
			}
		}
		if (k == 4) {
			cout << ans;
			return 0;
		}
		x = nx;
		y = ny;
		ans += a[x][y];
		a[x][y] = -1;
	}
}
