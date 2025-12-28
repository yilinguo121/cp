#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
void ans(int n, int f, int t) {
	if (!n) return;
	ans(n - 1, f, 6 - f - t);
	cout << f << ' ' << t << '\n';
	ans(n - 1, 6 - f - t, t);
}
int main() {
	int n;
	cin >> n;
	cout << (1 << n) - 1 << '\n';
	ans(n, 1, 3);
}
