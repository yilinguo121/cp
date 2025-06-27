#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k, type;
	cin >> n >> k >> type;
	vector<pair<int, int>> v;
	for (int i = 0;i < n;i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({a, 1});
		v.push_back({b, -1});
	}
	sort(v.begin(), v.end());
	int m = v.size();
	long long now = 0, sum = 0, ans = 0;
	bool open = 0;
	int last = -1;
	now += v[0].second;
	for (int i = 1;i < m;i++) {
		if (i - 1 != last and v[i].first == v[i - 1].first and v[i].second + v[i - 1].second == 0) {
			last = i;
			now += v[i].second;
			continue;
		}
		if (now >= k) {
			ans += v[i].first - v[i - 1].first;
			if (!open) {
				sum++;
				open = 1;
			}
		}
		if (now < k) {
			if (open) {
				sum++;
				open = 0;
			}
		}
		now += v[i].second;
	}
	if (now < k) {
		if (open) {
			sum++;
			open = 0;
		}
	}
	cout << ans;
	if (type) cout << ' ' << sum;

}

