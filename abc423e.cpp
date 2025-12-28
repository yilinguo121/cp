#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
// 算每個ai出現的次數 = a[i](i - l + 1)(r - i + 1)
// a[i] * (-i^2 + (r + 1 + l - 1) * i + ((- l + 1) * (r + 1))
// => a[i] * (-i^2 + (r + 1 + l - 1) * i - ((l - 1) * (r + 1))
signed main() {
	int n, q;
	cin >> n >> q;
	vector<int> pre1(n + 1), pre2(n + 1), pre3(n + 1);
	for (int i = 1;i <= n;i++) {
		int x;
		 cin >> x;
		 pre1[i] = pre1[i - 1] + x;
		 pre2[i] = pre2[i - 1] + x * i;
		 pre3[i] = pre3[i - 1] + x * i * i;
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << -(pre3[r] - pre3[l - 1]) + (l + r) * (pre2[r] - pre2[l - 1]) - (l - 1) * (r + 1) * (pre1[r] - pre1[l - 1]) << '\n';
	}
}

