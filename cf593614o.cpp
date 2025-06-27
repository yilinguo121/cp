#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> v(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<int> q;
	vector<int> vis(n + 1), cnt(n + 1);
	for (int i = 1;i <= n;i++) {
		cnt[i] = v[i].size();
		if (v[i].size() < k) {
			q.push(i);
			vis[i] = 1;
		}
	}
	int ans = 0;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		ans++;
		for (auto nt : v[t]) {
			if (vis[nt]) continue;
			cnt[nt]--;
			if (cnt[nt] >= k) continue;
			q.push(nt);
			vis[nt] = 1;
		}
	}
	cout << ans;
}

