#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n;
	cin >> n;
	vector<int> h(n);
	vector<pair<int, int>> v;
	int ans = 1;
	for (int i = 0;i < n;i++) {
		cin >> h[i];
		int cnt = 1;
		while (!v.empty() and h[i] >= v.back().first) {
			ans -= v.back().first * v.back().second;
			cnt += v.back().second;
			v.pop_back();
		}
		ans += cnt * h[i];
		cout << ans << ' ';
		v.push_back({h[i], cnt});
	}
}
