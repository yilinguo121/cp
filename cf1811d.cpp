#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<int> f(45, 1);
bool ans(int n, int x, int y) {
	if (n == 1) return 1;
	if (y >= f[n]) return ans(n - 1, y - f[n], x);
	if (y < f[n - 1]) return ans(n - 1, y, x);
	return 0;
}
int main() {
	IO
	int t;
	cin >> t;
	for (int i = 2;i <= 44;i++) f[i] = f[i - 1] + f[i - 2];
	while (t--) {
		int n, x, y;
		cin >> n >> x >> y;
		cout << (ans(n, x - 1, y - 1) ? "YES\n" : "NO\n");
	}
}
