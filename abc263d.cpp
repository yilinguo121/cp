#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, l, r;
	cin >> n >> l >> r;
	int sum = 0, ans = INF;
	for (int i = 1;i <= n;i++) {
		int x;
		cin >> x;
		sum = min(sum + x, i * l);
		ans = min(ans, sum + (n - i) * r);
	}
	cout << ans;
}
