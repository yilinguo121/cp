#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n;
	cin >> n;
	vector<vector<int>> v(n + 1);
	for (int i = 1;i < n;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<int> q;
	bitset<300001> vis;
	int ans = 0;
	for (auto t : v[1]) {
		int cnt = 1;
		q.push(t);
		vis[t] = 1;
		while (!q.empty()) {
			t = q.front();
			q.pop();
			for (auto nt : v[t]) {
				if (vis[nt] or nt == 1) continue;
				q.push(nt);
				vis[nt] = 1;
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}
	cout << n - ans;
}
