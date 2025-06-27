#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n;
	cin >> n;
	map<pair<int, int>, int> mp;
	vector<vector<int>> v(n + 1);
	for (int i = 1;i < n;i++) {
		int a, b, l;
		cin >> a >> b >> l;
		v[a].push_back(b);
		v[b].push_back(a);
		mp[{min(a, b), max(a, b)}] = l;
	}
	queue<int> q;
	vector<tuple<int, int, int>> ans(n + 1);
	vector<bool> vis(n + 1);
	q.push(1);
	ans[1] = {0, 0, 0};
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		for (auto nt : v[t]) {
			if (vis[nt]) continue;
			q.push(nt);
			ans[nt] = {get<0>(ans[t]) + 1, get<1>(ans[t]) + mp[{min(nt, t), max(nt, t)}], max(get<2>(ans[t]), mp[{min(nt, t), max(nt, t)}])};
			vis[nt] = 1;
		}
	}
	for (int i = 2;i <= n;i++) cout << get<0>(ans[i]) << ' ' << get<1>(ans[i]) << ' ' << get<2>(ans[i]) << '\n';
}

