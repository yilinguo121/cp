#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n;
	cin >> n;
	int ans;
	cin >> ans;
	for (int i = 1, ai;i < n;i++) {
		cin >> ai;
		ans = lcm(ans, ai);
	}
	cout << ans;
}

