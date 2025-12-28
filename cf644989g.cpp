#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	long long n, ans = 0, mp[(1 << 20) + 5] = {};
	cin >> n;
	vector<int> a(n), b(n), c(n), d(n), x, y;
	for (auto &t : a) cin >> t;
	for (auto &t : b) cin >> t;
	for (auto &t : c) cin >> t;
	for (auto &t : d) cin >> t;
	for (auto &i : c) for (auto &j : d) mp[(i ^ j)]++;
	for (auto &i : a) for (auto &j : b) ans += mp[(i ^ j)];
	cout << ans;
}
