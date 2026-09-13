#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << (((2 * b - a) % 3 == 0 and (2 * a - b) % 3 == 0 and 2 * b >= a and 2 * a >= b) ? "YES\n" : "NO\n");
	}
}
