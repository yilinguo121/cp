#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed	 main() {
	IO
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1);
	int a, b;
	int need = 1;
	vector<int> cnt(n + 1);
	while (cin >> a >> b) {
		v[a].push_back(b);
		v[b].push_back(a);
		cnt[a]++;
		cnt[b]++;
		need = max(need, max(cnt[a], cnt[b]));
	}
	vector<bool> vis(n + 1);
	int ans = 1;
	for (int i = 1;i <= n;i++) {
		if (vis[i]) continue;
		queue<int> q;
		q.push(i);
		vis[i] = 1;
		int now = 1;
		while (!q.empty()) {
			auto t = q.front();
			q.pop();
			now *= (m - cnt[t]);
			for (auto nt : v[t]) {
				if (vis[nt]) continue;
				cnt[nt]--;
				q.push(nt);
				vis[nt] = 1;
			}
		}
		ans *= now;
	}
	cout << (m < need ? 0 : ans) << '\n' << need;
}
