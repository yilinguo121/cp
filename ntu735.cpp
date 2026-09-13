#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
vector<int> v, a;
void f(int l, int r) {
	if (l >= r) return;
	int m = (l + r) / 2;
	f(l, m), f(m + 1, r);
	int i = l, j = m + 1, k = l;
	while (i <= m and j <= r) {
		if (v[i] <= v[j]) a[k++] = v[i++];
		else a[k++] = v[j++];
	}
	while (i <= m) a[k++] = v[i++];
	while (j <= r) a[k++] = v[j++];
	for (int i = l;i <= r;i++) v[i] = a[i];
}
signed main() {
	int n;
	cin >> n;
	a.resize(n);
	v.resize(n);
	for (auto &x : v) cin >> x;
	f(0, n - 1);
	for (auto &x : v) cout << x << ' ';
}
