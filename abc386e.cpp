#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
vector<int> v;
int n, k, ans, sum;
void dfs(int id, int now, int get) {
	if (get == k) {
		ans = max(ans, now ^ sum);
		return;
	}
	if (get + (n - id) < k) return;
	dfs(id + 1, now ^ v[id], get + 1);
	dfs(id + 1, now, get);
}
signed main() {
	cin >> n >> k;
	v.resize(n);
	for (auto &x : v) cin >> x, sum ^= x;
	if (2 * k > n) k = n - k;
	else sum = 0;
	dfs(0, 0, 0);
	cout << ans;
}
