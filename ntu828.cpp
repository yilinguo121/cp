#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
int n;
vector<vector<int>> v(200001);
map<pair<int, int>, int> mp;
int ans[2][100001] = {};
int bfs(int x, int t) {
	queue<int> q;
	q.push(x);
	ans[t][x] = 0;
	pair<int, int> MAX = {0, 0};
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (auto nx : v[x]) {
			if (ans[t][nx] != -1) continue;
			q.push(nx);
			ans[t][nx] = ans[t][x] + mp[{min(x, nx), max(x, nx)}];
			if (ans[t][nx] > MAX.second) MAX = {nx, ans[t][nx]};
		}
	}
	return MAX.first;
}
signed main() {
	IO;
	cin >> n;
	for (int i = 1;i < n;i++) {
		int a, b, l;
		cin >> a >> b >> l;
		v[a].push_back(b);
		v[b].push_back(a);
		mp[{min(a, b), max(a, b)}] = l;
	}
	memset(ans, -1, sizeof(ans));
	int far = bfs(1, 0);
	memset(ans, -1, sizeof(ans));
	bfs(bfs(far, 0), 1);
	for (int i = 1;i <= n;i++) cout << max(ans[0][i], ans[1][i]) << ' ';
}
