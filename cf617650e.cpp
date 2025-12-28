#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
int n, m, ans;
vector<vector<pair<int, int>>> v;
int cnt[2000001];
void dfs(int t, int now, int k) {
	int x = abs(k);
	int old_cntk = cnt[x];
	now -= x * cnt[x] * cnt[x];
	if (k > 0) cnt[x]++;
	if (k < 0) cnt[x]--;
	now += x * cnt[x] * cnt[x];
	ans ^= now;
	for (auto [nt, w] : v[t]) dfs(nt, now, w);
	cnt[x] = old_cntk;
}
signed main() {
	IO
	cin >> n >> m;
	v.resize(m + 1);
	int now = 0;
	while(n--) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	for (int i = 1;i <= 2000000;i++) now += i * cnt[i] * cnt[i];
	for (int i = 1;i <= m;i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back({i, y});
	}
	dfs(0, now, 0);
	cout << ans;
}

