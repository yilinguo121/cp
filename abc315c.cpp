#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), cmp);
	int ans = 0;
	for (int i = 1;i < n;i++) {
		if (v[0].first == v[i].first) ans = max(ans, v[0].second + v[i].second / 2);
		else ans = max(ans, v[0].second + v[i].second);
	}
	cout << ans;
}

