#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n, k;
	cin >> n >> k;
	vector<int> v(2 * n);
	for (int i = 0;i < 2 * n;i++) {
		if (i < n) cin >> v[i];
		else v[i] = v[i % n];
	}
	vector<int> nxt(2 * n + 1, 2 * n);
	for (int i = 0, j = 0, sum = 0;i < 2 * n;i++) {
		while (j < 2 * n and sum + v[j] <= k) sum += v[j++];
		nxt[i] = j, sum -= v[i];
	}
	vector<vector<int>> up(20, vector<int>(2 * n + 1, 2 * n));
	up[0] = nxt;
	for (int i = 1;i < 20;i++) for (int j = 0;j <= 2 * n;j++) up[i][j] = up[i - 1][up[i - 1][j]];
	int ans = INF;
	for (int i = 0;i < n;i++) {
		int now = i, cnt = 0;
		for (int j = 19;j >= 0;j--) if (up[j][now] < i + n) now = up[j][now], cnt += (1 << j);
		ans = min(ans, cnt + 1);
	}
	cout << ans;
}

