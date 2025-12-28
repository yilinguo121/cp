#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first + a.second > b.first + b.second;
}
signed main() {
	IO
	int n, m;
	cin >> n >> m;
	vector<int> sum1, sum2;
	for (int i = 0;i < n;i++) {
		int cnt = 0;
		for (int j = 0;j < m;j++) {
			int x;
			cin >> x;
			cnt += x;
		}
		sum1.push_back(cnt);
		cnt = 0;
		for (int j = m;j < 2 * m;j++) {
			int x;
			cin >> x;
			cnt += x;
		}
		sum2.push_back(cnt);
	}
	vector<pair<int, int>> p;
	for (int i = 0;i < n;i++) p.push_back({sum1[i], sum2[i]});
	sort(p.begin(), p.end(), cmp);
	sort(sum1.begin(), sum1.end());
	sort(sum2.begin(), sum2.end());
	int i = (n + 1) / 2;
	while (i < n and p[i].first + p[i].second == p[i - 1].first + p[i - 1].second) {
		i++;
	}
	map<int, int> mp;
	int MAX = 0;
	for (;i < n;i++) {
		if (n - (upper_bound(sum1.begin(), sum1.end(), p[i].first) - sum1.begin() + 1) + 1 < (n + 1) / 2) mp[p[i].first + p[i].second]++, MAX = max(mp[p[i].first + p[i].second], MAX);
		else if (n - (upper_bound(sum2.begin(), sum2.end(), p[i].second) - sum2.begin() + 1) + 1 < (n + 1) / 2) mp[p[i].first + p[i].second]++, MAX = max(mp[p[i].first + p[i].second], MAX);
	}
	for (auto [x, y] : mp) {
		if (y == MAX) {
			cout << x;
			return 0;
		}
	}
	cout << -1;
}
