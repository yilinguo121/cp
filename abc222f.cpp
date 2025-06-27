#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
int n;
vector<vector<int>> v(400005);
map<pair<int, int>, int> mp;
int ans[2][400005] = {};
int bfs(int x, int t) {
	int start = x;
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
	for (int i = 1;i <= n;i++) {
		int x;
		cin >> x;
		v[i].push_back(i + n);
		v[i + n].push_back(i);
		mp[{i, i + n}] = x;
	}
	memset(ans, -1, sizeof(ans));
	int far1 = bfs(1, 0);
	memset(ans, -1, sizeof(ans));
	int far2 = bfs(far1, 0);
	bfs(far2, 1);
	for (int i = 1;i <= n;i++) cout << max((far1 == i + n ? -1 : ans[0][i]), (far2 == i + n ? -1 : ans[1][i])) << '\n';
}
