#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, m, k, s;
	cin >> n >> m >> k >> s;
	vector<vector<int>> v(n), from(k);
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		x--;
		from[x].push_back(i);
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	vector<vector<int>> dis(k, vector<int>(n, INF));
	queue<int> q;
	for (int i = 0;i < k;i++) {
		for (auto x : from[i]) {
			dis[i][x] = 0;
			q.push(x);
		}
		while (!q.empty()) {
			int t = q.front();
			q.pop();
			for (auto x : v[t]) {
				if (dis[i][x] != INF) continue;
				q.push(x);
				dis[i][x] = dis[i][t] + 1;
			}
		}
	}
	vector<int> a(k);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < k;j++) a[j] = dis[j][i];
		nth_element(a.begin(), a.begin() + s, a.end());
		int ans = 0;
		for (int j = 0;j < s;j++) ans += a[j];
		cout << ans << ' ';
	}
}

