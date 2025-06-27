#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int n, k;
vector<vector<pair<int, int>>> v;
bool f(int m) {
	bitset<505> vis;
	int cnt = 0;
	for (int i = 1;i <= n;i++) {
		if (vis[i]) continue;
		queue<int> q;
		cnt++;
		q.push(i);
		while (!q.empty()) {
			auto t = q.front();
			q.pop();
			for (auto [nt, x] : v[t]) {
				if (vis[nt]) continue;
				if (x >= m) continue;
				vis[nt] = 1;
				q.push(nt);
			}
		}
	}
	return cnt >= k;
}
int main() {
	IO
	cin >> n >> k;
	v.resize(n + 1);
	int l = INF, r = 0, ans;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			int x;
			cin >> x;
			if (i != j) v[i].push_back({j, x});
			r = max(r, x);
			l = min(l, x);
		}
	}
	while (l <= r) {
		int m = (l + r) / 2;
		if (f(m)) {
			l = m + 1;
			ans = m;
		}
		else r = m - 1;
	}
	cout << ans;
}
