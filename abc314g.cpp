#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, m, h, sum = 0;
	cin >> n >> m >> h;
	map<int, int> mp;
	set<pair<int, int>> a, b;
	vector<int> ans;
	for (int i = 0;i < n;i++) {
		int x, y;
		cin >> x >> y;
		if (mp[y]) {
			if (a.find({mp[y], y}) == a.end()) b.erase({mp[y], y});
			else {
				sum -= mp[y];
				a.erase({mp[y], y});
			}
		}
		mp[y] += x;
		if (!b.empty() and b.begin()->first < mp[y]) b.insert({mp[y], y});
		else {
			a.insert({mp[y], y});
			sum += mp[y];
		}
		while (!a.empty() and sum >= h) {
			b.insert(*a.rbegin());
			sum -= a.rbegin()->first;
			a.erase(prev(a.end()));
		}
		while (!b.empty() and sum + b.begin()->first < h) {
			a.insert(*b.begin());
			sum += b.begin()->first;
			b.erase(b.begin());
		}
		ans.push_back(b.size());
	}
	for (int i = 0;i <= m;i++) cout << upper_bound(ans.begin(), ans.end(), i) - ans.begin() << ' ';
}
