#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
#define int long long
vector<vector<int>> v;
int n, x, ans;
void dfs(int id, int now) {
	if (id == n) {
		ans += (now == x);
		return;
	}
	for (auto t : v[id]) {
		if (now > x / t) continue;
		dfs(id + 1, now * t);
	}
}
signed main() {
	cin >> n >> x;
	v.resize(n);
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		v[i].resize(k);
		for (auto &t : v[i]) cin >> t;
	}
	dfs(0, 1);
	cout << ans;
}
