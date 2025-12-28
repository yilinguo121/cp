#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
priority_queue<int> q;
int sum = 0, n, k, t;
vector<int> v;
bool flag = 0;
int now = 0;
void dfs(int id, int cnt) {
	if (cnt == k) {
		if (flag) q.push(sum - now);
		else q.push(now);
		return;
	}
	if (id + (k - cnt) > n) return;
	now += v[id];
	dfs(id + 1, cnt + 1);
	now -= v[id];
	dfs(id + 1, cnt);
}
signed main() {
	IO
	cin >> n >> k >> t;
	v.resize(n);
	for (auto &x : v) cin >> x, sum += x;
	if (k > n / 2) flag = 1, k = n - k;
	dfs(0, 0);
	int ans = 0;
	while (t--) {
		ans += q.top();
		q.pop();
	}
	cout << ans;
}

