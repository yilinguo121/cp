#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<vector<int>> v;
vector<int> now;
int n, m, q;
void dfs(int id, int t) {
	if (id == n) {
		v.push_back(now);
		return;
	}
	for (int i = t;i <= m;i++) {
		now.push_back(i);
		dfs(id + 1, i);
		now.pop_back();
	}
}
int main() {
	cin >> n >> m >> q;
	dfs(0, 1);
	vector<int> a(q), b(q), c(q), d(q);
	for (int i = 0;i < q;i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
	int ans = 0;
	for (auto x : v) {
		int now = 0;
		for (int i = 0;i < q;i++) {
			if (x[b[i] - 1] - x[a[i] - 1] == c[i]) now += d[i];
		}
		ans = max(now, ans);
	}
	cout << ans;
}

