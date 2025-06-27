#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	pair<int, int> v[n] = {};
	for (int i = 0;i < n;i++) {
		cin >> v[i].first >> v[i].second;
	}
	double ans = -1e18;
	sort(v, v + n);
	for (int i = 1;i < n;i++) {
		ans = max(ans, (double)(v[i].second - v[i - 1].second) / (v[i].first - v[i - 1].first));
	}
	cout << fixed << setprecision(10) << ans;
}

