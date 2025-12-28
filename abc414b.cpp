#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<pair<char, int>> v(n);
	int sum = 0;
	int MAX = 0;
	for (auto &[x, w] : v) cin >> x >> w, sum += w, MAX = max(MAX, w);
	if (sum > 100 or MAX > 100) cout << "Too Long";
	else {
		for (auto [x, w] : v) {
			while (w--) cout << x;
		}
	}
}
