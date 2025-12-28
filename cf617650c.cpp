#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<vector<pair<int, int>>> v;
vector<int> ans1, ans2, ans3;
void dfs(int t, int p) {
	for (auto [nt, len] : v[t]) {
		if (nt == p) continue;
		ans1[nt] = ans1[t] + 1;
		ans2[nt] = ans2[t] + len;
		ans3[nt] = max(ans3[t], len);
		dfs(nt, t);
	}
}
int main() {
	IO
	int n;
	cin >> n;
	v.resize(n + 1);
	ans1.resize(n + 1);
	ans2.resize(n + 1);
	ans3.resize(n + 1);
	for (int i = 0;i < n - 1;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}
	dfs(1, -1);
	for (int i = 2;i <= n;i++) cout << ans1[i] << ' ' << ans2[i] << ' ' << ans3[i] << '\n';
}

