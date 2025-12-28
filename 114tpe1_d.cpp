#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1);
	vector<int> a(n + 1);
	for (int i = 1;i <= n;i++) cin >> a[i];
	while (m--) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int ans = 0;
	for (int i = 1;i <= n;i++) {
		while (a[i]) {
			set<int> st;
			int mn = INF;
			queue<int> q;
			vector<bool> vis(n + 1);
			vis[i] = 1;
			q.push(i);
			while (!q.empty()) {
				auto t = q.front();
				q.pop();
				mn = min(mn, a[t]);
				st.insert(t);
				for (auto nt : v[t]) {
					if (vis[nt] or !a[nt]) continue;
					q.push(nt);
					vis[nt] = 1;
				}
			}
			ans += mn;
			for (auto x : st) a[x] -= mn;
		}
	}
	cout << ans;
}
