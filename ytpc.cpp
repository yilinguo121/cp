#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
#define int long long
signed main() {
	IO
	int n;
	cin >> n;
	int ans = 0;
	vector<int> a(n), b(n);
	bool flag1 = 0, flag2 = 0;
	for (int i = 0;i < n;i++) {
		cin >> a[i] >> b[i];
		if (a[i] < b[i]) {
			ans += a[i];
			flag1 = 1;
		}
		else {
			ans += b[i];
			flag2 = 1;
		}
	}
	if (!flag1) {
		int pos = 0;
		for (int i = 0;i < n;i++) {
			if (a[i] - b[i] < a[pos] - b[pos]) pos = i;
		}
		ans += a[pos] - b[pos];
	}
	if (!flag2) {
		int pos = 0;
		for (int i = 0;i < n;i++) {
			if (b[i] - a[i] < b[pos] - a[pos]) pos = i;
		}
		ans += b[pos] - a[pos];
	}
	cout << ans;
}
