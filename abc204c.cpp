#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	int ans = 0;
	for (int i = 1;i <= n;i++) {
		vector<bool> vis(n + 1);
		queue<int> q;
		q.push(i);
		vis[i] = 1;
		while (!q.empty()) {
			int t = q.front();
			q.pop();
			for (auto nt : v[t]) {
				if (vis[nt]) continue;
				q.push(nt);
				vis[nt] = 1;
			}
		}
		for (int j = 0;j <= n;j++) if (vis[j]) ans++;
	}
	cout << ans;
}
