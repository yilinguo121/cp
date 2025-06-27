#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1);
	while (m--) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	vector<bool> vis(n + 1);
	vector<int> pa(n + 1);
	queue<int> q;
	vis[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (t == n) {
			break;
		}
		for (auto x : v[t]) {
			if (!vis[x]) {
				q.push(x);
				vis[x] = 1;
				pa[x] = t;
			}
		}
	}
	if (vis[n]) {
		vector<int> ans;
		while (pa[n] or n == 1) {
			ans.push_back(n);
			n = pa[n];
		}
		reverse(ans.begin(), ans.end());
		cout << ans.size() << '\n';
		for (auto x : ans) cout << x << ' ';
	}
	else cout << "IMPOSSIBLE";
}

