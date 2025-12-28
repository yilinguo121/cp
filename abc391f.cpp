#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
int f(int x, int y, int z) {
	return x * y + y * z + z * x;
}
signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n), c(n);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;
	for (auto &x : c) cin >> x;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	priority_queue<tuple<int, int, int, int>> q;
	q.push({f(a[n - 1], b[n - 1], c[n - 1]), n - 1, n - 1, n - 1});
	int ans = 0;
	tuple<int, int, int, int> last = {0, -1, -1, -1};
	while (k--) {
		if (last == q.top()) {
			q.pop();
			k++;
			continue;
		}
		auto [s, x, y, z] = q.top();
		last = q.top();
		q.pop();
		ans = s;
		if (x - 1 >= 0) q.push({f(a[x - 1], b[y], c[z]), x - 1, y, z});
		if (y - 1 >= 0) q.push({f(a[x], b[y - 1], c[z]), x, y - 1, z});
		if (z - 1 >= 0) q.push({f(a[x], b[y], c[z - 1]), x, y, z - 1});
	}
	cout << ans;
}
