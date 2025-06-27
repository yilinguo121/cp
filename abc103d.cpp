#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v(m);
	for (auto &[x, y] : v) cin >> x >> y;
	sort(v.begin(), v.end(), cmp);
	int last = -1, ans = 0;
	for (auto [x, y] : v) {
		if (x >= last) {
			ans++;
			last = y;
		}
	}
	cout << ans;
}

