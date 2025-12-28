#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n;
	cin >> n;
	map<int, int> mp;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		mp[x]++;
	}
	priority_queue<pair<int, int>> q;
	for (auto [x, y] : mp) q.push({y, x});
	vector<pair<int, int>> ans;
	while (q.size() >= 2) {
		auto [l, x] = q.top();
		q.pop();
		auto [r, y] = q.top();
		q.pop();
		ans.push_back({x, y});
		if (l - 1) q.push({l - 1, x});
		if (r - 1) q.push({r - 1, y});
	}
	cout << ans.size() << '\n';
	for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
}

