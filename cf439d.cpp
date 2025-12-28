#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
int n, m;
vector<int> a, b;
int f(int k) {
	int cnt = 0;
	for (auto x : a) {
		if (x >= k) break;
		cnt += k - x;
	}
	for (auto x : b) {
		if (x <= k) break;
		cnt += x - k;
	}
	return cnt;
}
signed main() {
	IO
	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	for (int &x : a) cin >> x;
	for (int &x : b) cin >> x;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	int l = 1, r = 1000000000;
	while (r - l >= 3) {
		int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
		if (f(m1) < f(m2)) r = m2 - 1;
		else l = m1 + 1;
	}
	int ans = INF;
	for (int i = l;i <= r;i++) ans = min(ans, f(i));
	cout << ans;
}
