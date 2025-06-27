#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n;
	cin >> n;
	vector<vector<int>> v(n + 1);
	vector<int> t(n + 1);
	bitset<200001> vis;
	queue<int> q;
	for (int i = 1;i <= n;i++) {
		cin >> t[i];
		int k;
		cin >> k;
		while (k--) {
			int x;
			cin >> x;
			v[i].push_back(x);
		}
	}
	int ans = 0;
	q.push(n);
	vis[n] = 1;
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		ans += t[x];
		for (auto nx : v[x]) {
			if (vis[nx]) continue;
			q.push(nx);
			vis[nx] = 1;
		}
	}
	cout << ans;
}

