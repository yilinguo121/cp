#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int, int>>> v(n + 1);
	while (m--) {
		int a, b, w;
		cin >> a >> b >> w;
		v[a].push_back({b, w});
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	vector<int> cnt(n + 1);
	q.push({0, 1});
	while (!q.empty()) {
		auto [d, t] = q.top();
		q.pop();
		if (++cnt[t] > k) continue;
		if (t == n) cout << d << ' ';
		for (auto [nt, nd] : v[t]) q.push({d + nd, nt});
	}
}
