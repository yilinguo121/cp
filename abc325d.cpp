#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i].first >> v[i].second;
		v[i].second += v[i].first;
	}
	sort(v.begin(), v.end());
	int now = 0, ans = 0, pos = 0;
	priority_queue<int, vector<int>, greater<int>> q;
	while (pos < n or !q.empty()) {
		now++;
		if (q.empty()) now = max(now, v[pos].first);
		while (pos < n and v[pos].first <= now) {
			q.push(v[pos].second);
			pos++;
		}
		while (!q.empty() and q.top() < now) q.pop();
		if (!q.empty()) {
			ans++;
			q.pop();
		}
	}
	cout << ans;
}

