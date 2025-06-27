#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n, m, k;
	cin >> n >> m >> k;
	vector<int>	h(n + m);
	deque<int> q, p;
	vector<pair<int, int>> ans;
	for (int i = 1;i <= n;i++) {
		cin >> h[i];
		while (!q.empty() and q.front() <= i - m) q.pop_front();
		while (!p.empty() and p.front() <= i - m) p.pop_front();
		while (!q.empty() and h[q.back()] <= h[i]) q.pop_back();
		while (!p.empty() and h[p.back()] >= h[i]) p.pop_back();
		q.push_back(i);
		p.push_back(i);
		if (i >= 2 and abs(h[q.front()] - h[p.front()]) == k) ans.push_back({max(1ll, i - m + 1), min(i, n)});
	}
	for (int i = n + 1;i <= n + m;i++) {
		while (!q.empty() and q.front() <= i - m) q.pop_front();
		while (!p.empty() and p.front() <= i - m) p.pop_front();
		if (!q.empty() and !p.empty() and abs(h[q.front()] - h[p.front()]) == k) ans.push_back({max(1ll, i - m + 1), min(i, n)});
	}
	cout << ans.size() << '\n';
	for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
}

