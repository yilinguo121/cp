#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
const int mod = 1e9 + 7;
signed main() {
	int n;
	cin >> n;
	vector<vector<pair<int, int>>> v(n + 1);
	for (int i = 1;i < n;i++) {
		int a, b, w;
		cin >> a >> b >> w;
		v[a].push_back({b, w});
		v[b].push_back({a, w});
	}
	vector<int> vis(n + 1, -1);
	queue<int> q;
	q.push(1);
	vis[1] = 0;
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		for (auto [nt, w] : v[t]) {
			if (vis[nt] != -1) continue;
			q.push(nt);
			vis[nt] = vis[t] ^ w;
		}
	}
	int ans = 0;
	for (int i = 0;i < 61;i++) {
		int w = (1ll << i) % mod, cnt[2] = {}; // 這裡要用1ll !!!!!!!
		for (int j = 1;j <= n;j++) cnt[(vis[j] >> i) & 1]++;
		ans = (ans + (w * (cnt[0] % mod * cnt[1] % mod) % mod) % mod) % mod;
	}
	cout << ans;
}

