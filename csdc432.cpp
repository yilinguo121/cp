#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int a, b;
	double x;
	cin >> a >> b >> x;
	int c = ceil(x);
	cout << fixed << setprecision(0) << ((a < 18 or a >= 65 ? 100 : 200) + max(0ll, (b - 100) * 2) + (c > 1 ? min(5ll, c) - 1 : 0) * 50 + (c > 5 ? c - 5 : 0) * 30) * (b > 200 and c > 3 ? 0.8 : 1);
}
