#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n), b(m);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int i = 0, ans = 0;
	for (auto x : a) {
		while (i < m and b[i] + k < x) i++;
		if (i >= m) break;
		if (x - k <= b[i] and b[i] <= x + k) {
			ans++;
			i++;
		}
	}
	cout << ans;
}

