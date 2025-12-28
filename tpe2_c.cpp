#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> v(n, vector<int> (m));
		int ans = 0;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				cin >> v[i][j];
				if (i) ans += abs(v[i - 1][j] - v[i][j]);
				if (!i or i == n - 1) ans += v[i][j];
			}
		}
		cout << ans << '\n';
	}
}

