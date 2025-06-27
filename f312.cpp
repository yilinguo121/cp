#include<bits/stdc++.h>
using namespace std;
int main() {
	int a1, b1, c1, a2, b2, c2, n;
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> n;
	int ans = -10000;
	for (int i = 0;i <= n;i++) {
		int j = n - i;
		int sum = (a1 * i * i + b1 * i + c1) + (a2 * j * j + b2 * j + c2);
		ans = max(sum, ans);
	}
	cout << ans << '\n';
}
