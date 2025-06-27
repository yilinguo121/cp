#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n, k;
	cin >> n >> k;
	int cnt = 0, ans = 1;
	while (n--) {
		int x;
		cin >> x;
		cnt += x;
		if (cnt > k) {
			ans++;
			cnt = x;
		}
	}
	cout << ans;
}

