#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1);
	vector<int> ans(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<int> q;
	q.push(1);
	ans[1] = 1;
	int k = 1;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (auto nt : v[t]) {
			if (ans[nt] == ans[t]) {
				cout << "IMPOSSIBLE";
				return 0;
			}
			if (ans[nt]) continue;
			q.push(nt);
			ans[nt] = 3 - ans[t];
		}
		if (q.empty()) {
			for (;k <= n;k++) {
				if (ans[k]) continue;
				q.push(k);
				ans[k] = 1;
				break;
			}
		}
	}
	for (int i = 1;i <= n;i++) cout << ans[i] << ' ';
}
