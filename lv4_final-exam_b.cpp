#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<vector<int>> v(n + 1);
	for (int i = 1;i < n;i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int k;
	cin >> k;
	int p;
	cin >> p;
	int x, y;
	cin >> x >> y;
	queue<pair<int, int>> q;
	vector<bool> vis(n + 1);
	q.push({x, 0});
	vis[x] = 1;
	while (!q.empty()) {
		auto [t, cnt] = q.front();
		q.pop();
		if (t == y) {
			cout << cnt;
			return 0;
		}
		for (auto nt : v[t]) {
			if (!vis[nt]) q.push({nt, cnt + 1});
			vis[nt] = 1;
		}
	}
}

