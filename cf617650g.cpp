#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
int n, sum, ans;
vector<int> v;
void dfs(int id, int now) {
	if (id == n) {
		ans = min(ans, abs(now - (sum - now)));
		return;
	}
	dfs(id + 1, now);
	dfs(id + 1, now + v[id]);
}
signed main() {
	cin >> n;
	v.resize(n);
	for (auto &x : v) {
		cin >> x;
		sum += x;
	}
	ans = INF;
	dfs(0, 0);
	cout << ans;
}

