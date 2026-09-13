#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
int f(int a, int b) {
	if (a and b) return 0;
	if (a + b == 1) return 2;
	return 1;
}
signed main() {
	IO
	int n, k;
	cin >> n;
	k = min(n, 20ll);
	vector<int> a(n), b(n), ans(3);
	vector<vector<int>> r(k, vector<int>(n)), c(n, vector<int>(k));
	for (auto &x : a) cin >> x;
	b[0] = a[0];
	for (int i = 1;i < n;i++) cin >> b[i];
	for (int i = 0;i < n;i++) r[0][i] = a[i], c[i][0] = b[i];
	for (int i = 0;i < k;i++) r[i][0] = b[i], c[0][i] = a[i];
	for (int i = 1;i < k;i++) for (int j = 1;j < n;j++) r[i][j] = f(r[i - 1][j], r[i][j - 1]), c[j][i] = f(c[j - 1][i], c[j][i - 1]);
	for (int i = 0;i < k - 1;i++) for (int j = 0;j < n;j++) ans[r[i][j]]++;
	for (int i = k - 1;i < n;i++) for (int j = 0;j < k - 1;j++) ans[c[i][j]]++;
	for (int j = k - 1;j < n;j++) ans[r[k - 1][j]] += n - j;
	for (int i = k;i < n;i++) ans[c[i][k - 1]] += n - i;
	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
}
