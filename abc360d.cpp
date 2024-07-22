#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, t, ans = 0;
	cin >> n >> t;
	vector<pair<int, int>> v(n);
	string s;
	cin >> s;
	for (int i = 0;i < n;i++) {
		cin >> v[i].first;
		v[i].second = s[i] - '0';
	}
	sort(v.begin(), v.end());
	vector<int> l, r;
	for (int i = 0;i < n;i++) {
		if (v[i].second == 1) {
			r.push_back(v[i].first);
		}
		else {
			l.push_back(v[i].first);
		}
	}
	for (int i = 0;i < r.size();i++) {
		auto lb = lower_bound(l.begin(), l.end(), r[i]);
		auto ub = upper_bound(l.begin(), l.end(), r[i] + 2 * t);
		ans += distance(lb, ub);
	}
	cout << ans << '\n';
}
