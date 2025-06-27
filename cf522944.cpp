#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	IO
	int n, k;
	cin >> n >> k;
	int i = n, j = 1;
	int ans = 2e9;
	while (i >= 1 and j <= n) {
		cout << "? " << i << ' ' << j << '\n';
		cout.flush();
		int x;
		cin >> x;
		if (x >= k) {
			i--;
			ans = min(ans, x);
		}
		else j++;
	}
	cout << "! " << (ans != 2e9 ? ans : -1);
}

