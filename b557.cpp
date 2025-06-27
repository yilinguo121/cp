#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<int, int> mp;
		for (int i = 0;i < n;i++) {
			int a;
			cin >> a;
			mp[a * a]++;
		}
		int ans = 0;
		for (auto x : mp) {
			for (auto y : mp) {
				if (x.first >= y.first) break;
				ans += x.second * y.second * mp[x.first + y.first];
			}
		}
		cout << ans / 2 << '\n';
	}
}

