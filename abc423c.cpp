#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, r;
	cin >> n >> r;
	vector<int> v(n);
	int ans = 0;
	for (auto &x : v) {
		cin >> x;
		ans += (!x);
	}
	bool flag = 0;
	for (int i = 0;i < r;i++) {
		if (!v[i]) flag = 1;
		if (flag and v[i]) ans += 2;
	}
	flag = 0;
	for (int i = n - 1;i >= r;i--) {
		if (!v[i]) flag = 1;
		if (flag and v[i]) ans += 2;
	}
	cout << ans;
}
