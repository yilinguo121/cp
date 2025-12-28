#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	vector<vector<int>> v(n);
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a - 1].push_back(b - 1);
	}
	vector<int> less(n, INF);
	int ans = -INF;
	for (int i = 0;i < n;i++) {
		less[i] = min(a[i], less[i]);
		for (auto ni : v[i]) {
			ans = max(ans, a[ni] - less[i]);
			less[ni] = min(less[ni], less[i]);
		}
	}
	cout << ans;
}
