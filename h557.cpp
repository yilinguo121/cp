#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, r;
	cin >> n >> r;
	map<pair<int, int>, int> mp;
	while (n--) {
		int x, y;
		cin >> x >> y;
		for (int i = x - r;i <= x + r;i++) {
			for (int j = y - r;j <= y + r;j++) {
				if ((x - i) * (x - i) + (y - j) * (y - j) <= r * r) {
					mp[{i, j}]++;
				}
			}
		}
	}
	long long ans = 0;
	for (auto x : mp) {
		if (x.second % 2) ans++;
	}
	cout << ans;
}

