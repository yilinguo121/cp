#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1);
	vector<int> cnt(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		cnt[b]++;
	}
	queue<int> q;
	for (int i = 1;i <= n;i++) if (!cnt[i]) q.push(i);
	vector<int> ans;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		ans.push_back(x);
		for (auto nx : v[x]) {
			cnt[nx]--;
			if (!cnt[nx]) q.push(nx);
		}
	}
	if (ans.size() != n) cout << "IMPOSSIBLE";
	else {
		for (auto x : ans) cout << x << ' ';
	}
}

