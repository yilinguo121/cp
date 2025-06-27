#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	IO
	int n, m;
	cin >> n >> m;
	vector<vector<int>> st(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		st[a].push_back(b);
		st[b].push_back(a);
	}
	for (int i = 1;i <= n;i++) sort(st[i].begin(), st[i].end());
	int q, pa[n + 1] = {};
	cin >> q;
	while (q--) {
		bool flag = 0;
		int x;
		cin >> x;
		if (pa[x]) {
			vector<int> ans;
			while (x != 1) {
				ans.push_back(x);
				x = pa[x];
			}
			ans.push_back(1);
			reverse(ans.begin(), ans.end());
			for (auto t : ans) cout << t << ' ';
			cout << '\n';
			continue;
		}
		bool vis[n + 1] = {};
		queue<int> q;
		q.push(1);
		while (!q.empty()) {
			if (flag) break;
			int t = q.front();
			q.pop();
			for (auto k : st[t]) {
				if (vis[k]) continue;
				pa[k] = t;
				q.push(k);
				vis[k] = 1;
				if (k == x) {
					vector<int> ans;
					while (x != 1) {
						ans.push_back(x);
						x = pa[x];
					}
					ans.push_back(1);
					reverse(ans.begin(), ans.end());
					for (auto y : ans) cout << y << ' ';
					cout << '\n';
					flag = 1;
					break;
				}
			}
		}
	}
}

