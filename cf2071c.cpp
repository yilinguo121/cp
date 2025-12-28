#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, s, e;
		cin >> n >> s >> e;
		vector<vector<int>> v(n + 1);
		for (int i = 1; i < n;i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		queue<int> q;
		vector<bool> vis(n + 1);
		q.push(e);
		vis[e] = 1;
		vector<int> ans;
		while (!q.empty()) {
			auto t = q.front();
			q.pop();
			ans.push_back(t);
			for (auto nt : v[t]){
				if (vis[nt]) continue;
				q.push(nt);
				vis[nt] = 1;
			}
		}
		reverse(ans.begin(), ans.end());
		for (auto x : ans) cout << x << ' ';
		cout << '\n';
	}
}

