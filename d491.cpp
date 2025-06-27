#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	unsigned long long ans = 0;
	long long l, r;
	cin >> l >> r;
	if (l > r) swap(l, r);
	for (long long i = l;i <= r;i++) if (i % 2 == 0) ans += i;
	cout << ans;
}

