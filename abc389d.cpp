#include <bits/stdc++.h>
using namespace std;
int main() {
	int r;
	cin >> r;
	long long ans = 0;
	for (int i = 1, j = r;i <= r;i++) {
		while (j >= 0 and 1ll * (2 * i + 1) * (2 * i + 1) + 1ll * (2 * j + 1) * (2 * j + 1) > 4ll * r * r) j--;
		ans += j + 1;
	}
	cout << ans * 4 + 1;
}
