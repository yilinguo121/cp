#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	int a = INF, b = 0, c = INF, d = 0;
	while (n--) {
		int x, y;
		cin >> x >> y;
		a = min(x, a);
		b = max(x, b);
		c = min(y, c);
		d = max(y, d);
	}
	cout << max(b - a, d - c) / 2 + (max(b - a, d - c) % 2 ? 1 : 0);
}
