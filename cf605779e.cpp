#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
int n, m, t;
vector<vector<int>> v(200000);
unordered_map<int, bool> a;
int vis[200000];
int ans[2];
void bfs(int s, bool way) {
	ans[way] = 1e18;
	queue<int> q;
	memset(vis, -1, sizeof(vis));
	q.push(s);
	vis[s] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (a[x]) ans[way] = min(ans[way], vis[x]);
		for (auto nx : v[x]) {
			if (vis[nx] != -1) continue;
			q.push(nx);
			vis[nx] = vis[x] + 1;
		}
	}
}
signed main() {
	IO
	cin >> n >> m >> t;
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int k;
	cin >> k;
	while (k--) {
		int x;
		cin >> x;
		a[x] = 1;
	}
	bfs(0, 0);
	bfs(n - 1, 1);
	long long cnt = ans[0] + ans[1] + 1;
	if (vis[0] != -1) cnt = min(cnt, vis[0]);
	if (cnt >= 1e18 or (vis[0] == -1 and !t)) cout << -1;
	else cout << cnt;
}

