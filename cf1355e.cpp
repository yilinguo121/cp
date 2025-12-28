#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
int n, x, y, m;
vector<int> v, a;
int f(int t) {
	int id = upper_bound(v.begin(), v.end(), t) - v.begin();
	int move = min(t * id - a[id], (a[n] - a[id]) - (n - id) * t);
	return  move * m + (t * id - a[id] - move) * x + ((a[n] - a[id]) - (n - id) * t - move) * y;
}
signed main() {
	cin >> n >> x >> y >> m;
	v.resize(n);
	a.resize(n + 1);
	for (int &x : v) cin >> x;
	sort(v.begin(), v.end());
	for (int i = 0;i < n;i++) a[i + 1] = a[i] + v[i];
	m = min(m, x + y);
	int l = 0, r = v.back();
	while (r - l > 3) {
		int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
		if (f(m1) < f(m2)) r = m2 - 1;
		else l = m1 + 1;
	}
	int ans = INF;
	for (int i = l;i <= r;i++) ans = min(ans, f(i));
	cout << ans;
}

