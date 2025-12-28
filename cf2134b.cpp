#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		vector<int> a = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
		int p = 0;
		for (auto x : a) {
			if (k % x) {
				p = x;
				break;
			}
		}
		for (auto &x : v) {
			cin >> x;
			while (x % p) x += k;
			cout << x << ' ';
		}
		cout << '\n';
	}
}
