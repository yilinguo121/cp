#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, m;
	cin >> n >> m;
	vector<int> t(n);
	for (auto &x : t) cin >> x;
	vector<pair<int, int>> v(m);
	for (auto &[x, y] : v) cin >> x >> y;
	sort(t.begin(), t.end());
	sort(v.begin(), v.end());
	priority_queue<int, vector<int>, greater<int>> q;
	int ans = 0, j = 0;
	for (auto x : t) {
		while (j < m and v[j].first <= x) q.push(v[j++].second);
		while (!q.empty() and q.top() < x) q.pop();
		ans += q.size();
	}
	cout << ans;
}
