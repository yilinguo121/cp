#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0;i < n;i++) cin >> a[i];
	int l = 0, r = x + *max_element(a.begin(), a.end()), ans = 0;
	while (l <= r) {
		int m = (l + r) / 2, sum = 0;
		for (int i = 0;i < n;i++) sum += max(m - a[i], 0);
		if (sum <= x) {
			l = m + 1;
			ans = m;
		}
		else r = m - 1;
	}
	cout << ans;
}

