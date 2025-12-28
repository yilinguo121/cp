#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<vector<char>> a;
vector<vector<int>> b;
vector<int> n, pos, dp, m;
int k;
int dfs(int id) {
	if (dp[id] != -1) return dp[id];
	int now = 0;
	for (int i = 0;i < k;i++) if (pos[i] < n[i]) {
		for (int j = i + 1;j < k;j++) if (pos[j] < n[j] and a[i][pos[i]] == a[j][pos[j]]) {
			now = max(now, b[i][pos[i]++] + b[j][pos[j]++] + dfs(id + m[i] + m[j]));
			pos[i]--, pos[j]--;
		}
	}
	return dp[id] = now;
}
int main() {
	cin >> k;
	a.resize(k), b.resize(k), n.resize(k), pos.resize(k), m.resize(k);
	int t = 1;
	for (int i = 0;i < k;i++) {
		cin >> n[i];
		a[i].resize(n[i]), b[i].resize(n[i]);
		for (int j = 0;j < n[i];j++) cin >> a[i][j] >> b[i][j];
		m[i] = t;
		t *= n[i] + 1;
	}
	dp.resize(t, -1);
	cout << dfs(0);
}

