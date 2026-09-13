#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, t;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << 1 << ' ' << 1 << '\n';
		if (n >= 2) cout << 1 << ' ' << 2 << '\n';
		for (int i = 3;i <= n;i++) cout << i << ' ' << i << '\n';
		cout << '\n';
	}
}

