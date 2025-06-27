#include <bits/stdc++.h>
using namespace std;
int main() {
	int x, y;
	cin >> x >> y;
	int n;
	cin >> n;
	int ans = 1e9;
	int p, q;
	while (n--) {
		int a, b;
		cin >> a >> b;
		if ((a - x) * (a - x) + (b - y) * (b - y) < ans) {
			p = a;
			q = b;
			ans = (a - x) * (a - x) + (b - y) * (b - y);
		}
	}
	cout << p << ' ' << q;
}

