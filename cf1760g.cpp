#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<vector<pair<int, int>>> v;
int n, s, e;
set<int> st;
void dfs(int t, int pa, int now) {
	st.insert(now);
	for (auto [nt, w] : v[t]) {
		if (nt == pa or nt == e) continue;
		dfs(nt, t, now ^ w);
	}
}
bool ans(int t, int pa, int now) {
	for (auto [nt, w] : v[t]) {
		if (nt == pa) continue;
		if (st.count(now ^ w)) return 1;
		if (ans(nt, t, now ^ w)) return 1;
	}
	return 0;
}
int main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> s >> e;
		v.clear();
		v.resize(n + 1);
		st.clear();
		for (int i = 0;i < n - 1;i++) {
			int a, b, w;
			cin >> a >> b >> w;
			v[a].push_back({b, w});
			v[b].push_back({a, w});
		}
		dfs(s, 0, 0);
		cout << (ans(e, 0, 0) ? "YES\n" : "NO\n");
	}
}
