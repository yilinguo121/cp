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
		int n, s1, s2;
		cin >> n >> s1 >> s2;
		map<int, int> mp;
		vector<pair<int, int>> v;
		for (int i = 1;i <= n;i++) {
			int x;
			cin >> x;
			v.push_back({i, x});
		}
		sort(v.begin(), v.end(), [](auto a, auto b) {
			return a.second > b.second;
		});
		int cnt1 = 1, cnt2 = 1;
		vector<int> a, b;
		for (auto [x, y] : v) {
			if (s1 * cnt1 <= s2 * cnt2) {
				a.push_back(x);
				cnt1++;
			}
			else {
				b.push_back(x);
				cnt2++;
			}
		}
		cout << a.size() << ' ';
		for (auto x : a) cout << x << ' ';
		cout << '\n' << b.size() << ' ';
		for (auto x : b) cout << x << ' ';
		cout << '\n';
	}
}
