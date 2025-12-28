#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int n, m;
vector<string> s;
unordered_map<string, bool> mp;
vector<bool> vis;
void dfs(int id, string now) {
	if (now.size() > 16) return;
	if (id == n) {
		if (now.size() >= 3 and !mp.count(now)) {
			cout << now;
			exit(0);
		}
		return;
	}
	for (int i = 0;i < n;i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		if (now.empty()) dfs(id + 1, now + s[i]);
		else {
			for (int j = 1;j <= 16;j++) {
				if (now.size() + j + (n - id) > 16) break;
				dfs(id + 1, now + string(j, '_') + s[i]);
			}
		}
		vis[i] = 0;
	}
}
int main() {
	IO
	cin >> n >> m;
	s.resize(n);
	vis.resize(n);
	for (auto &x : s) cin >> x;
	while (m--) {
		string x;
		cin >> x;
		mp[x] = 1;
	}
	dfs(0, "");
	cout << -1;
}
