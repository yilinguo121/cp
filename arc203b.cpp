#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, p = 0, q = 0;
		cin >> n;
		vector<int> a(n), b(n);
		for (auto &x : a) {
			cin >> x;
			p += x;
		}
		for (auto &x : b) {
			cin >> x;
			q += x;
		}
		cout << ((a == b) or (p == q and p >= 2) or (p == q and p == 1 and b[0] + b[n - 1] == 0 and a[0] + a[n - 1] == 0) ? "Yes\n" : "No\n");
	}
}
