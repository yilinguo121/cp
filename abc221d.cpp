#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0;i < n;i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({a, 1});
		v.push_back({a + b, -1});
	}
	sort(v.begin(), v.end());
	int t = 1;
	int ans[n + 1] = {};
	for (int i = 1;i < v.size();i++) {
		ans[t] += v[i].first - v[i - 1].first;
		t += v[i].second;
	}
	for (int i = 1;i <= n;i++) cout << ans[i] << ' ';
}
