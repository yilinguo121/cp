#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
#define int long long
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int cnt = 0;
		while (a >= 1) {
			tie(a, b) = pair<int, int>({b - a, a});
			cnt++;
		}
		cout << cnt << '\n';
	}
}

