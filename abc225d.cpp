#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int n, q;
	cin >> n >> q;
	vector<int> l(n + 1), r(n + 1);
	while (q--) {
		int t, x, y;
		cin >> t;
		if (t == 1) {
			cin >> x >> y;
			r[x] = y;
			l[y] = x;
		}
		if (t == 2) {
			cin >> x >> y;
			r[x] = 0;
			l[y] = 0;
		}
		if (t == 3) {
			cin >> x;
			vector<int> ans;
			while (l[x]) x = l[x];
			while (x) {
				ans.push_back(x);
				x = r[x];
			}
			cout << ans.size() << ' ';
			for (auto a : ans) cout << a << ' ';
			cout << '\n';
		}
	}
}
