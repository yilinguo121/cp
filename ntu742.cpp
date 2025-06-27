#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n;
	cin >> n;
	vector<int> a(n), l(n), r(n), v;
	for (int i = 0;i < n;i++) cin >> a[i];
	for (int i = 0;i < n;i++) {
		while (!v.empty() and a[i] <= a[v.back()]) v.pop_back();
		l[i] = i - (v.empty() ? -1 : v.back());
		v.push_back(i);
	}
	v.clear();
	for (int i = n - 1;i >= 0;i--) {
		while (!v.empty() and a[i] < a[v.back()]) v.pop_back();
		r[i] = (v.empty() ? n : v.back()) - i;
		v.push_back(i);
	}
	int ans = 0;
	for (int i = 0;i < n;i++) ans += a[i] * r[i] * l[i];
	cout << ans;
}
