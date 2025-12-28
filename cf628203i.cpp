#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int w, k;
	cin >> w >> k;
	cout << 2 * k << ' ' << 2 * (2 * k - 2) << '\n';
	cout << 1 << ' ';
	for (int i = 2;i < 2 * k;i++) cout << w - 2 << ' ';
	cout << 1 << '\n';
	for (int i = 2;i < 2 * k;i++) cout << 1 << ' ' << i << '\n' << i << ' ' << 2 * k << '\n';
}

