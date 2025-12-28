#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long 
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n), c(n);
	for (int i = 0;i < n;i++) cin >> a[i] >> b[i] >> c[i];
	vector<int> ans(n);
	queue<int> q;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int now = 0, i = 0;
	while (i < n or !pq.empty()) {
		int in = (i < n ? a[i] : INF), out = (!pq.empty() ? pq.top().first : INF);
		if (out <= in) {
			while (!pq.empty() and pq.top().first == out) {
				now -= c[pq.top().second];
				pq.pop();
			}
			while (i < n and a[i] <= out) q.push(i++);
			while (!q.empty() and now + c[q.front()] <= k) {
				ans[q.front()] = out;
				now += c[q.front()];
				pq.push({out + b[q.front()], q.front()});
				q.pop();
			}
		}
		else {
			while (i < n and a[i] <= in) q.push(i++);
			while (!q.empty() and now + c[q.front()] <= k) {
				ans[q.front()] = in;
				now += c[q.front()];
				pq.push({in + b[q.front()], q.front()});
				q.pop();
			}
		}
	}
	for (auto x : ans) cout << x << '\n';
}
