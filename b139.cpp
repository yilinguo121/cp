#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int l, n;
	cin >> l >> n;
	int a[l + 1] = {};
	while (n--) {
		int x, y;
		cin >> x >> y;
		a[x]++;
		a[y + 1]--;
	}
	int ans = 0;
	for (int i = 0;i <= l;i++) {
		if (i) a[i] += a[i - 1];
		if (!a[i]) ans++;
	}
	cout << ans;
}

