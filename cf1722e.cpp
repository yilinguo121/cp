#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int a[1005][1005] = {};
		int n, q;
		cin >> n >> q;
		while (n--) {
			int h, w;
			cin >> h >> w;
			a[h][w] += (h * w);
		}
		for (int i = 1;i < 1001;i++) {
			for (int j = 1;j < 1001;j++) {
				a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
			}
		}
		while (q--) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << a[x1][y1] - a[x2 - 1][y1] - a[x1][y2 - 1] + a[x2 - 1][y2 - 1] << '\n';
		}
	}
}
