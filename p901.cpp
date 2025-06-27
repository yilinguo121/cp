#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0;i <n;i++) cin >> v[i];
	int h, w;
	cin >> h >> w;
	int a[h][w];
	for (int i = 0;i < h;i++) {
		for (int j = 0;j < w;j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0;i < n;i++) {
		bool flag = 0;
		for (int j = 0;j < h;j++) {
			for (int k = 0;k < w;k++) {
				if (a[j][k] == v[i]) {
					cout << j + 1 << ' ' << k + 1 << '\n';
					flag = 1;
					break;
				}
			}
			if (flag) break;
		}
		if (!flag) cout << -1 << '\n';
	}
}

