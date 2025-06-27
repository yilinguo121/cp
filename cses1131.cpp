#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int n;
vector<vector<int>> v(200001);
pair<int, int> bfs(int x) {
	vector<int> dis(n + 1), vis(n + 1);
	queue<int> q;
	q.push(x);
	vis[x] = 1;
	pair<int, int> ans = {0, 0};
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		for (auto nt : v[t]) {
			if (vis[nt]) continue;
			q.push(nt);
			vis[nt] = 1;
			dis[nt] = dis[t] + 1;
			if (dis[nt] > ans.second) ans = {nt, dis[nt]};
		}
	}
	return ans;
}
int main() {
	cin >> n;
	for (int i = 1;i < n;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cout << bfs(bfs(1).first).second;
}

