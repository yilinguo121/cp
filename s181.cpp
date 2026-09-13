#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
int n, m, r, k, t, cnt = 0;
vector<int> v, ans, class_cnt;
void dfs(int pos, int used, int deep) {
	if (deep == k) {
		if (++cnt == t) {
			sort(ans.begin(), ans.end());
			for (auto x : ans) cout << x << ' ';
			exit(0);
		}
		return;
	}
	if (pos + (k - deep) > m * r) return;
	if (!(used & (1ll << v[pos])) and class_cnt[pos / r] < 2) {
		ans[deep] = pos + 1;
		class_cnt[pos / r]++;
		dfs(pos + 1, used | (1ll << v[pos]), deep + 1);
		class_cnt[pos / r]--;
	}
	dfs(pos + 1, used, deep);
}
signed main() {
	cin >> n >> m >> r >> k >> t;
	v.resize(m * r);
	ans.resize(k);
	class_cnt.resize(m);
	for (auto &x : v) cin >> x;
	dfs(0, 0, 0);
}

