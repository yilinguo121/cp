#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<pair<int, int>> v;
int n;
bool f(int x) {
	vector<pair<int, int>> a;
	for (int i = 0;i < n;i++) if (i != x) a.push_back(v[i]);
	for (int i = 2;i < a.size();i++) if ((a[1].first - a[0].first) * (a[i].second - a[0].second) != (a[1].second - a[0].second) * (a[i].first - a[0].first)) return 0;
	return 1;
}
int main() {
	cin >> n;
	v.resize(n);
	for (auto &[x, y] : v) cin >> x >> y;
	if (f(-1)) {
		cout << "-1 -1";
		return 0;
	}
	for (int i = 0;i < n;i++) if (f(i)) cout << v[i].first << ' ' << v[i].second;
}
