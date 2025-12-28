#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max() / 4;
int main() {
	int n;
	while (cin >> n) {
		if (!n) break;
		vector<vector<int>> v(n, vector<int>(n, INF));
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				int x;
				cin >> x;
				if (!x) continue;
				v[i][j] = x;
			}
		}
		for (int k = 0;k < n;k++) {
			for (int i = 0;i < n;i++) {
				for (int j = 0;j < n;j++) {
					v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
				}
			}
		}
		int ans = INF;
		for (int i = 0;i < n;i++) ans = min(ans, v[i][i]);
		cout << (ans == INF ? -1 : ans) << '\n';
	}
}
