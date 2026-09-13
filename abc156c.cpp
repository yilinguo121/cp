#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	int ans = INF;
	for (int i = 1;i <= 100;i++) {
		int now = 0;
		for (auto x : v) {
			now += (i - x) * (i - x);
		}
		ans = min(ans, now);
	}
	cout << ans;
}

