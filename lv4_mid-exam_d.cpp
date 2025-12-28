#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n;
	cin >> n;
	vector<int> v(n);
	int mx = -INF, mn = INF, sum = 0;
	for (auto &x : v) {
		cin >> x;
		if (x >= 0) sum += x, mn = min(mn, x);
		else mx = max(mx, x);
	}
	cout << max(sum + mx, sum - mn);
}

