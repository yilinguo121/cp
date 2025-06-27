#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}
int main() {
	int n, d;
	cin >> n >> d;
	vector<pair<int, int>> v(n);
	for (auto &[x, y] : v) cin >> x >> y;
	sort(v.begin(), v.end(), cmp);
	int last = -1, ans = 0;
	for (auto [x, y] : v) {
		if (x > last) {
			ans++;
			last = y + d - 1;
		}
	}
	cout << ans;
}
