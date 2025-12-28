#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int s, a, b, x;
	cin >> s >> a >> b >> x;
	int ans = 0;
	while (x > 0) {
		ans += s * min(a, x);
		x -= min(a, x);
		x -= b;
	}
	cout << ans;
}

