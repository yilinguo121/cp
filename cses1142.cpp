#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n;
	cin >> n;
	vector<int> v, a(n + 2);
	v.push_back(0);
	int ans = 0;
	for (int i = 1;i <= n + 1;i++) {
		if (i <= n) cin >> a[i];
		while (v.size() > 0 and a[i] < a[v.back()]) {
			int h = v.back();
			v.pop_back();
			ans = max(ans, (i - v.back() - 1) * a[h]);
		}
		v.push_back(i);
	}
	cout << ans;
}
