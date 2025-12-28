#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<pair<int, int>> v;
bool vis[12][12];
int n, h, w;
vector<bool> use;
bool check(int x, int y, int id, bool change) {
	if (x + (change ? v[id].second : v[id].first) - 1 > h) return 0;
	if (y + (change ? v[id].first : v[id].second) - 1 > w) return 0;
	for (int i = 0;i < (change ? v[id].second : v[id].first);i++) {
		for (int j = 0;j < (change ? v[id].first : v[id].second);j++) {
			if (vis[x + i][y + j]) return 0;
		}
	}
	return 1;
}
void dfs(int x, int y, int need) {
	if (y > w) dfs(x + 1, 0, need);
	if (x > h) {
		cout << "Yes";
		exit(0);
	}
	while (vis[x][y]) {
		y++;
		if (y > w) x++, y = 0;
		if (x > h) {
			cout << "Yes";
			exit(0);
		}
	}
	bool flag = 1;
	for (int i = 0;i < n;i++) {
		if (use[i]) continue;
		if (need < v[i].first * v[i].second) break;
		use[i] = 1;
		if (check(x, y, i, 0)) {
			flag = 0;
			for (int dx = 0;dx < v[i].first;dx++) {
				for (int dy = 0;dy < v[i].second;dy++) {
					vis[x + dx][y + dy] = 1;
				}
			}
			dfs(x, y + v[i].second, need - v[i].first * v[i].second);
			for (int dx = 0;dx < v[i].first;dx++) {
				for (int dy = 0;dy < v[i].second;dy++) {
					vis[x + dx][y + dy] = 0;
				}
			}
		}
		if (check(x, y, i, 1)) {
			flag = 0;
			for (int dx = 0;dx < v[i].second;dx++) {
				for (int dy = 0;dy < v[i].first;dy++) {
					vis[x + dx][y + dy] = 1;
				}
			}
			dfs(x, y + v[i].first, need - v[i].first * v[i].second);
			for (int dx = 0;dx < v[i].second;dx++) {
				for (int dy = 0;dy < v[i].first;dy++) {
					vis[x + dx][y + dy] = 0;
				}
			}
		}
		use[i] = 0;
	}
	if (flag) return;
}
bool cmp (pair<int, int> a, pair<int, int> b) {
	return a.first * a.second < b.first * b.second;
}
int main() {
	cin >> n >> h >> w;
	v.resize(n);
	use.resize(n);
	for (auto &[x, y] : v) cin >> x >> y;
	for (int i = 0;i <= 11;i++) vis[0][i] = vis[h + 1][i] = vis[i][0] = vis[i][w + 1] = 1;
	sort(v.begin(), v.end(), cmp);
	dfs(1, 1, h * w);
	cout << "No";
}
