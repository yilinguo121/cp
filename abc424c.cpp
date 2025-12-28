#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<vector<int>> v(n + 1);
	queue<int> q;
	for (int i = 1;i <= n;i++) {
		int a, b;
		cin >> a >> b;
		if (!a and !b) q.push(i);
		else {
			v[a].push_back(i);
			v[b].push_back(i);
		}
	}
	vector<bool> vis(n + 1);
	int ans = 0;
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		ans++;
		for (auto nt : v[t]) {
			if (vis[nt]) continue;
			q.push(nt);
			vis[nt] = 1;
		}
	}
	cout << ans;
}
