#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
int f(int x) {
	if (!(x % 4)) return x;
	if (x % 4 == 1) return 1;
	if (x % 4 == 2) return x + 1;
	return 0;
}
signed main() {
	int a, b;
	cin >> a >> b;
	cout << (f(b) ^ f(a - 1));
}
