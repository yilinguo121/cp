#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int n;
	cin >> n;
	vector<vector<int>> v(10);
	while (n--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<string> q;
	map<string, int> dis;
	unordered_set<string> vis;
	string s;
	for (int i = 0;i < 8;i++) {
		char c;
		cin >> c;
		s += c;
	}
	q.push(s);
	dis[s] = 0;
	vis.insert(s);
	while (!q.empty()) {
		s = q.front();
		q.pop();
		if (s == "12345678") {
			cout << dis[s];
			return 0;
		}
		int t = 0;
		for (auto x : s) t += x - '0';
		t = 45 - t;
		for (auto x : v[t]) {
			string ns = s;
			for (auto &y : ns) if (y - '0' == x) y = t + '0';
			if (vis.insert(ns).second) {
				dis[ns] = dis[s] + 1;
				q.push(ns);
			}
		}
	}
	cout << -1;
}

