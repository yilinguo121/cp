#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n), s(n);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;
	for (int i = 0, sum = 0;i < n;i++) sum += a[i] - b[i], s[i] = sum;
	sort(s.begin(), s.end());
	int ans = 0;
	for (int i = 0;i < n;i++) ans += abs(s[i] - s[n / 2]);
	cout << ans;
}
