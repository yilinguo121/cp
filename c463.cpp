#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n;
	cin >> n;
	vector<vector<int>> v(n + 1);
	vector<vector<int>> pa(n + 1);
	bitset<100001> st;
	for (int i = 1;i <= n;i++) {
		int x;
		cin >> x;
		while (x--) {
			int a;
			cin >> a;
			v[i].push_back(a);
			pa[a].push_back(i);
			st[a] = 1;
		}
	}
	int start;
	for (int i = 1;i <= n;i++) {
		if (!st[i]) {
			start = i;
			break;
		}
	}
	queue<int> q, p;
	vector<int> vis(n + 1);
	q.push(start);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (v[t].empty()) {
			p.push(t);
			vis[t] = 0;
		}
		for (auto nt : v[t]) {
			q.push(nt);
		}
	}
	int ans = 0;
	while (!p.empty()) {
		auto t = p.front();
		p.pop();
		for (auto nt : pa[t]) {
			if (vis[t] + 1 < vis[nt]) continue;
			p.push(nt);
			vis[nt] = vis[t] + 1;
		}
	}
	for (int i = 1;i <= n;i++) ans += vis[i];
	cout << start << '\n' << ans;
}
