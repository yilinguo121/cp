#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n, m, k;
	cin >> n >> m >> k;
	queue<int> q;
	bitset<100000> vis;
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		q.push(x);
		vis[x] = 1;
	}
	vector<int> sz(n, k);
	vector<vector<int>> v(m);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < k;j++) {
			int x;
			cin >> x;
			v[x].push_back(i);
		}
	}
	vector<vector<int>> s(n);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < k;j++) {
			int x;
			cin >> x;
			s[i].push_back(x);
		}
	}
	int ans = 0;
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		for (auto nx : v[x]) {
			sz[nx]--;
			if (sz[nx]) continue;
			ans++;
			for (auto y : s[nx]) {
				if (vis[y]) continue;
				q.push(y);
				vis[y] = 1;
			}
		}
	}
	cout << ans;
}

