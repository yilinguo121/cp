#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v(m);
	for (int i = 0;i < m;i++) cin >> v[i].first;
	for (int i = 0;i < m;i++) cin >> v[i].second;
	sort(v.begin(), v.end());
	if (v[m - 1].first != n) v.push_back({n, 0});
	if (v[0].first != 1) {
		cout << -1;
		return 0;
	}
	m = v.size();
	int ans = 0;
	for (int i = 1;i < m;i++) {
		if (v[i - 1].second <= v[i].first - v[i - 1].first) {
			cout << -1;
			return 0;
		}
		ans += (((v[i - 1].second - 1) + v[i - 1].second - (v[i].first - v[i - 1].first)) * (v[i].first - v[i - 1].first + 1)) / 2;
		v[i - 1].second = 1;
		v[i].second += v[i - 1].second - (v[i].first - v[i - 1].first);
	}
	if (v[m - 1].second == 1) cout << ans;
	else cout << -1;
}

