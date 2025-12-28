#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
int n;
vector<int> v;
int f(int k) {
	int cnt = 0;
	for (auto x : v) cnt += abs(x - k);
	return cnt;
}
signed main() {
	IO
	cin >> n;
	v.resize(n);
	for (int &x : v) cin >> x;
	int l = *min_element(v.begin(), v.end()), r = *max_element(v.begin(), v.end());
	while (r - l >= 3) {
		int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
		if (f(m1) > f(m2)) l = m1 + 1;
		else r = m2 - 1;
	}
	int ans = INF;
	for (int i = l;i <= r;i++) ans = min(ans, f(i));
	cout << ans;
}
