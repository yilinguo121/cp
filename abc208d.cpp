#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max() / 2;
signed main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(n, INF));
	for (int i = 0;i < n;i++) v[i][i] = 0;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a - 1][b - 1] = min(v[a - 1][b - 1], c);
	}
	int ans = 0;
	for (int k = 0;k < n;k++) {
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
				ans += (v[i][j] != INF ? v[i][j] : 0);
			}
		}
	}
	cout << ans;
}
