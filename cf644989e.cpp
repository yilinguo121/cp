#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0;i < n;i++) cin >> x[i] >> y[i];
	vector<int> ans, d(n, INF);
	vector<bool> vis(n);
	vis[0] = 1;
	for (int i = 1;i < n;i++) d[i] = (x[0] - x[i]) * (x[0] - x[i]) + (y[0] - y[i]) * (y[0] - y[i]);
	for (int t = 1;t < n;t++) {
		int k = -1;
		for (int i = 0;i < n;i++) if (!vis[i] and (k == -1 or d[i] < d[k])) k = i;
		vis[k] = 1;
		ans.push_back(d[k]);
		for (int i = 0;i < n;i++) d[i] = min(d[i], (x[i] - x[k]) * (x[i] - x[k]) + (y[i] - y[k]) * (y[i] - y[k]));
	}
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	for (int i = 0;i < n - 1;i++) cout << ans[i] << '\n';
}
