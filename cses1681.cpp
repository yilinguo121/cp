#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1);
	vector<int> cnt(n + 1), dp(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		if (b == 1) continue;
		v[a].push_back(b);
		cnt[b]++;
	}
	if (1) {
		queue<int> q;
		for (int i = 2;i <= n;i++) if (!cnt[i]) q.push(i);
		while (!q.empty()) {
			auto t = q.front();
			q.pop();
			for (auto nt : v[t]) if (!--cnt[nt]) q.push(nt);
		}
	}
	queue<int> q;
	q.push(1);
	dp[1] = 1;
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		for (auto nt : v[t]) {
			dp[nt] = (dp[nt] + dp[t]) % 1000000007;
			if (!--cnt[nt]) {
				q.push(nt);
			}
		}
	}
	cout << dp[n] << '\n';
}

