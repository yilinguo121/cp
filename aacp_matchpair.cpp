#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n;
	cin >> n;
	map<int, int> mp;
	vector<int> v(n);
	for (auto &x : v) {
		cin >> x;
		mp[x]++;
	}
	vector<pair<int, int>> a;
	for (auto [x, cnt] : mp) a.push_back({cnt, x});
	sort(a.begin(), a.end());
	n = 0;
	for (auto [cnt, x] : a) for (int i = 0;i < cnt;i++) v[n++] = x;
	vector<pair<int, int>> ans;
	for (int i = 0;i < n / 2;i++) if (v[i] != v[i + n / 2]) ans.push_back({v[i], v[i + n / 2]});
	cout << ans.size() << '\n';
	for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
}
