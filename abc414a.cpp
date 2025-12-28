#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, l, r;
	cin >> n >> l >> r;
	int ans = 0;
	while (n--) {
		int a, b;
		cin >> a >> b;
		if (a <= l and b >= r) ans++;
	}
	cout << ans;
}

