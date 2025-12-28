#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto &x : v) cin >> x;
		vector<pair<bool, bool>> a(n); // right big / left small
		int now = 1e9;
		for (int i = 0;i < n;i++) {
			now = min(now, v[i]);
			if (now < v[i]) a[i].second = 1;
		}
		now = 0;
		for (int i = n - 1;i >= 0;i--) {
			now = max(now, v[i]);
			if (now > v[i]) a[i].first = 1;
		}
		for (int i = 0;i < n;i++) {
			cout << ((a[i].second and !a[i].first) or (!a[i].second and a[i].first) or (!a[i].second and !a[i].first));
		}
		cout << '\n';
	}
}
