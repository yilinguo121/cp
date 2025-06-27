#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
int f (int x) {
	int sum = 0;
	while (x > 0) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}
int ans (int l, int r, int x) {
	int sum = 0, cnt = 0;
	for (int i = l, j = l;j <= r;j++) {
		sum += f(j);
		while (i <= j and sum > x) {
			sum -= f(i++);
		}
		cnt += j - i + 1;
	}
	return cnt;
}
signed main() {
	int l, r, v1, v2;
	cin >> l >> r >> v1 >> v2;
	cout << ans(l, r, v2) - ans(l, r, v1 - 1);
}

