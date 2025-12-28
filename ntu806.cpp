#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (auto &[x, y] : v) cin >> x >> y;
	sort(v.begin(), v.end());
	vector<int> ans;
	for (auto [x, y] : v) {
		if (ans.empty() or y >= ans.back()) ans.push_back(y);
		else *upper_bound(ans.begin(), ans.end(), y) = y;
	}
	cout << ans.size();
}
