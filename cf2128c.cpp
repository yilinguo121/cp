#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
#define int long long
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		int now = INF;
		bool ans = 0;
		for (auto &x : v) {
			cin >> x;
			if (now * 2 <= x) {
				ans = 1;
			}
			now = min(now, x);
		}
		cout << (ans ? "NO\n" : "YES\n");
	}
}

