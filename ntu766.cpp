#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bitset<100001> vis;
	queue<int> q;
	int ans = 0;
	for (int i = 1;i <= n;i++) {
		if (vis[i]) continue;
		q.push(i);
		vis[i] = 1;
		int cnt = 0, point = 0;
		while (!q.empty()) {
			auto t = q.front();
			q.pop();
			cnt += v[t].size();
			point++;
			for (auto nt : v[t]) {
				if (vis[nt]) continue;
				q.push(nt);
				vis[nt] = 1;
			}
		}
		ans += cnt / 2 - (point - 1);
	}
	cout << ans;
}

