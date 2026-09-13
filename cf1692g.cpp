#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO;
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for (auto &x : v) cin >> x;
		int cnt = 0, ans = 0;
		for (int i = 0;i < n - 1;i++) cnt = (v[i] < 2 * v[i + 1] ? cnt + 1 : 0), ans += (cnt >= k);
		cout << ans << '\n';
	}
}
