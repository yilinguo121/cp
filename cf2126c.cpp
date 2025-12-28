#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for (auto &x : v) cin >> x;
		int now = v[k - 1];
		sort(v.begin(), v.end());
		for (auto x : v) {
			if (x <= now) continue;
			if (x - now <= now) now = x;
			else break;
		}
		cout << (now == v.back() ? "YES\n" : "NO\n");
	}
}

