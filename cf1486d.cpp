#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int n, k;
vector<int> v;
bool f(int x) {
	vector<int> a(n + 1);
	for (int i = 1;i <= n;i++) a[i] = a[i - 1] + (v[i - 1] >= x ? 1 : -1);
	int mn = INF;
	for (int i = k;i <= n;i++) {
		mn = min(mn, a[i - k]);
		if (a[i] - mn > 0) return 1;
	}
	return 0;
}
int main() {
	cin >> n >> k;
	v.resize(n);
	for (auto &x : v) cin >> x;
	int l = 1, r = *max_element(v.begin(), v.end()), ans = 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (f(m)) l = m + 1, ans = m;
		else r = m - 1;
	}
	cout << ans;
}

