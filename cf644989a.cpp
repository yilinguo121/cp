#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max() / 4;
int main() {
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n, INF));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> v[i][j];
		}
	}
	auto dis = v;
	int ans = INF;
	for (int k = 0;k < n;k++) {
		for (int i = 0;i < k;i++) {
			for (int j = i + 1;j < k;j++) {
				ans = min(ans, dis[i][j] + v[j][k] + v[k][i]);
			}
		}
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	cout << ans;
}
