#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1);
	vector<pair<int, int>> p(m);
	for (int i = 0;i < m;i++) {
		cin >> p[i].first >> p[i].second;
		v[p[i].first].push_back(p[i].second);
	}
	vector<int> pa(n + 1), dis(n + 1, -1);
	queue<int> q;
	q.push(1);
	dis[1] = 0;
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		for (auto x : v[t]) {
			if (dis[x] != -1) continue;
			q.push(x);
			dis[x] = dis[t] + 1;
			pa[x] = t;
		}
	}
	if (dis[n] == -1) {
		for (int i = 0;i < m;i++) cout << -1 << '\n';
		return 0;
	}
	for (int i = 0;i < m;i++) {
		int now = n;
		bool flag = 1;
		while (now != 1) {
			if (now == p[i].second and pa[now] == p[i].first) {
				flag = 0;
				break;
			}
			now = pa[now];
		}
		if (flag) {
			cout << dis[n] << '\n';
			continue;
		}
		vector<int> new_dis(n + 1, -1);
		q.push(1);
		new_dis[1] = 0;
		while (!q.empty()) {
			int t = q.front();
			q.pop();
			for (auto x : v[t]) {
				if (new_dis[x] != -1) continue;
				if (t == p[i].first and x == p[i].second) continue;
				q.push(x);
				new_dis[x] = new_dis[t] + 1;
			}
		}
		cout << new_dis[n] << '\n';
	}
}

