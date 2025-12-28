#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
#define int long long
int f(int x1, int x2, int y1, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
signed main() {
	IO	
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (auto &[x, y] : v) cin >> x >> y;
	sort(v.begin(), v.end());
	if (n == 2) cout << "2 " << f(v[1].first, v[0].first, v[1].second, v[0].second);
	else {
		if ((v[1].second - v[0].second) * (v[2].first - v[1].first) == (v[2].second - v[1].second) * (v[1].first - v[0].first)) cout << "3 " << f(v[2].first, v[0].first, v[2].second, v[0].second);
		else cout << "2 " << min({f(v[2].first, v[0].first, v[2].second, v[0].second), f(v[2].first, v[1].first, v[2].second, v[1].second), f(v[1].first, v[0].first, v[1].second, v[0].second)});
	}
}
