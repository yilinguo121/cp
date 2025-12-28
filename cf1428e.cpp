#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
vector<int> a, v;
int f(int i, int t) {
	int x = a[i] / t, r = a[i] % t;
	return (t - r) * x * x + r * (x + 1) * (x + 1);
}
signed main() {
	IO
	int n, k;
	cin >> n >> k;
	a.resize(n);
	v.assign(n, 1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	int ans = 0;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
		ans += f(i, 1);
		if (a[i] > 1) q.push({f(i, 2) - f(i, 1), i});
	}
	int need = k - n;
	while (need--) {
		int i = q.top().second;
		ans += q.top().first;
		v[i]++;
		if (v[i] < a[i]) q.push({f(i, v[i] + 1) - f(i, v[i]), i});
		q.pop();
	}
	cout << ans;
}
