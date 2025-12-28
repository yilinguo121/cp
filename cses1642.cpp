#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for (auto &t : v) cin >> t;
	unordered_map<int, pair<int, int>> mp;
	for (int i = 0;i < n;i++) {
		for (int j = i + 1;j < n;j++) {
			if (mp.find(x - v[i] - v[j]) != mp.end()) {
				auto [a, b] = mp.find(x - v[i] - v[j])->second;
				cout << a + 1 << ' ' << b + 1 << ' ' << i + 1 << ' ' << j + 1;
				return 0;
			}
		}
		for (int j = 0;j < i;j++) {
			if (!mp.count(v[i] + v[j])) mp[v[i] + v[j]] = {i, j};
		}
	}
	cout << "IMPOSSIBLE";
}
