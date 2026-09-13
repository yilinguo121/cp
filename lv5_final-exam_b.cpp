#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n;
	cin >> n;
	int mx = -1, ans = -1;
	string x;
	while (n--) {
		cin >> x;
		int now = stoll(x), nmx = mx;
		if (mx != -1) {
			for (auto t : x) nmx *= 10;
			ans = max(ans, nmx + now);
		}
		mx = max(mx, now);
	}
	cout << ans;
}

