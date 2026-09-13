#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int q;
	cin >> q;
	while (q--) {
		int t, x1, y1, x2, y2;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		for (int i = x1;i <= x2;i++) {
			for (int j = y1;j <= y2;j++) {
				if ((i - 1) & (j - 1)) cout << 'B';
				else cout << 'R';
			}
			cout << '\n';
		}
	}
}

