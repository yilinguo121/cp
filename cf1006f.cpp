#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
int n, m, k, ans;
vector<vector<unordered_map<int, int>>> mp;
vector<vector<int>> v;
void dfs1(int x, int y, int cnt, int now) {
	if (cnt == ((n - 1) + (m - 1)) / 2) {
		mp[x][y][now]++;
		return;
	}
	if (x + 1 < n) dfs1(x + 1, y, cnt + 1, now ^ v[x + 1][y]);
	if (y + 1 < m) dfs1(x, y + 1, cnt + 1, now ^ v[x][y + 1]);
}
void dfs2(int x, int y, int cnt, int now) {
	if (cnt == ((n - 1) + (m - 1) + 1) / 2) {
		if (mp[x][y].count(now ^ k ^ v[x][y])) ans += mp[x][y][now ^ k ^ v[x][y]];
		return;
	}
	if (x - 1 >= 0) dfs2(x - 1, y, cnt + 1, now ^ v[x - 1][y]);
	if (y - 1 >= 0) dfs2(x, y - 1, cnt + 1, now ^ v[x][y - 1]);
}
signed main() {
	IO
	cin >> n >> m >> k;
	v.resize(n, vector<int>(m));
	mp.resize(n, vector<unordered_map<int, int>>(m));
	for (auto &y : v) for (auto &x : y) cin >> x;
	dfs1(0, 0, 0, v[0][0]);
	dfs2(n - 1, m - 1, 0, v[n - 1][m - 1]);
	cout << ans;
}

