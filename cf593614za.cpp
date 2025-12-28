#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
vector<int> a, b, c, v;
int f(int i, int x) {
	return a[i] * x * x + b[i] * x + c[i];
}
signed main() {
	int n, k;
	cin >> n >> k;
	int ans = 0;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	v.resize(n);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	for (int i = 0;i < n;i++) {
		cin >> a[i] >> b[i] >> c[i];
		ans += f(i, 0);
		q.push({f(i, 1) - f(i, 0), i});
	}
	while (k--) {
		ans += q.top().first;
		int i = q.top().second;
		q.pop();
		v[i]++;
		q.push({f(i, v[i] + 1) - f(i, v[i]), i});
	}
	cout << ans;
}
