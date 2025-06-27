#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1);
	vector<int> sz(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
		sz[a]++;
	}
	queue<int> q;
	for (int i = 1;i <= n;i++) if (!sz[i]) q.push(i);
	int cnt = 0;
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		cnt++;
		for (auto nt : v[t]) if (!--sz[nt]) q.push(nt);
	}
	cout << n - cnt;
}

