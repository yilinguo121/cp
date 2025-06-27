#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) return a.second < b.second;
	return a.first > b.first;
}
signed main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), cmp);
	int t = v[0].second;
	int ans = 1;
	for (int i = 1;i < n;i++) {
		if (v[i].first >= t) {
			ans++;
			t = v[i].second;
		}
	}
	cout << ans;
}
