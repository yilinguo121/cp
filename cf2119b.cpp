#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
bool is(int a, int b, int c) {
	if ((a + b) * (a + b) >= c) return 0;
	if ((b - a) * (b - a) >= c) return 0;
	if ((a - b) * (a - b) >= c) return 0;
	return 1;
}
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x[2], y[2];
		cin >> n >> x[0] >> y[0] >> x[1] >> y[1];
		vector<int> v(n);
		int sum = 0;
		for (auto &x : v) {
			cin >> x;
			sum += x;
		}
		int dis = (x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]);
		if (sum * sum < dis) cout << "No\n";
		else {
			if (n == 2 and v[0] != v[1] and !dis) cout << "No\n";
			//else if (n == 2 and ((v[0] - v[1]) * (v[0] - v[1]) != dis or is(v[0], v[1], dis))) cout << "No\n";
			else cout << "Yes\n";
		}
	}
}
