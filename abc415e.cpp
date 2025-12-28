#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
vector<vector<int>> v;
vector<vector<int>> a;
vector<int> p;
int h, w;
int dx[2] = {1, 0};
int dy[2] = {0, 1};
void bfs(int m) {
	queue<tuple<int, int, int, int, int>> q;
	q.push({0, 0, 0, m, 0});
	while (!q.empty()) {
		auto [x, y, now, k, e] = q.front();
		q.pop();
		k = k + v[x][y] - p[now];
		a[x][y] = max(a[x][y] - e, k);
		for (int i = 0;i < 2;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= h or ny >= w) continue;
			q.push({nx, ny, now + 1, k, e + (a[x][y] < 0 ? abs(a[x][y]) : 0)});
		}
	}
}
signed main() {
	cin >> h >> w;
	v.resize(h, vector<int>(w));
	a.resize(h, vector<int>(w, -INF));
	int k = h + w - 1;
	p.resize(k);
	for (int i = 0;i < h;i++) {
		for (int j = 0;j < w;j++) {
			cin >> v[i][j];
		}
	}
	for (auto &x : p) cin >> x;
	bfs(0);
	cout << (a[h - 1][w - 1] < 0 ? abs(a[h - 1][w - 1]) : 0);
}
