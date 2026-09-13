#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	long long n, k;
	cin >> n >> k;
	int l = 1, r = n;
	while (n--) {
		if (r - l <= k) k -= r - l, cout << r-- << ' ';
		else cout << l++ << ' ';
	}
}
