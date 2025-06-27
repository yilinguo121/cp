#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<long long>::max();
signed main() {
	IO
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> v(n + 1), x(n + 1);
	for (int i = 1;i <= n;i++) {
		cin >> v[i];
		x[i] = x[i - 1] + v[i];
	}
	deque<int> q;
	int ans = -INF;
	for (int r = a;r <= n;r++) {
		int i = r - a;
		while (!q.empty() and x[i] <= x[q.back()]) q.pop_back();
		q.push_back(i);
		while (!q.empty() and q.front() < r - b) q.pop_front();
		ans = max(ans, x[r] - x[q.front()]);
	}
	cout << ans;
}

