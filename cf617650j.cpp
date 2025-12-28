#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int f(int n, int m, int k) {
	if (k == 1) return m % n;
	return (f(n - 1, m, k - 1) + m) % n;
}
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	cout << f(n, m, k) + 1;
}

