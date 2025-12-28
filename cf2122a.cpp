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
		cout << ((a > 2 and b >= 2) or (b > 2 and a >= 2) ? "YES\n" : "NO\n");
	}
}

