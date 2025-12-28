#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, j, k;
		cin >> n >> j >> k;
		vector<int> v(n);
		for (auto &x : v) cin >> x;
		int now = v[j - 1];
		sort(v.begin(), v.end());
		cout << (k == 1 and now < v.back() ? "NO\n" : "YES\n");
	}
}

