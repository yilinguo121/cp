#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
vector<vector<int>> v(2001);
unordered_set<string> st;
string f(int a, int b) {
	return to_string(a) + "," + to_string(b);
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1;i <= n;i++) v[i].clear();
		st.clear();
		vector<int> color(n + 1);
		for (int i = 1;i <= n;i++) cin >> color[i];
		while (m--) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		queue<tuple<int, int, int>> q;
		q.push({1, n, 0});
		st.insert(f(1, n));
		int ans = -1;
		while (!q.empty()) {
			auto [x, y, l] = q.front();
			q.pop();
			if (y == 1 and x == n) {
				ans = l;
				break;
			}
			for (auto nx : v[x]) {
				for (auto ny : v[y]) {
					if (color[nx] != color[ny] and st.insert(f(nx, ny)).second) {
						q.push({nx, ny, l + 1});
					}
				}
			}
		}
		cout << ans << '\n';
	}
}
