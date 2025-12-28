#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	int l = 1, r = n, ans = 1;
	while (l <= r) {
		int m = (l + r) / 2, x;
		cout << "? " << m << '\n';
		cout.flush();
		cin >> x;
		if (x) r = m - 1;
		else l = m + 1, ans = m;
	}
	cout << "! " << ans;
}
