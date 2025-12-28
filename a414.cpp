#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int x;
	while (cin >> x) {
		if (!x) break;
		cout << __builtin_popcount(x ^ (x + 1)) - 1 << '\n';
	}
}

