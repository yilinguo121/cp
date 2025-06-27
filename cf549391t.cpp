#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	map<long long, int> mp;
	long long ans = 0;
	while (n--) {
		int a;
		cin >> a;
		for (int j = 1;j <= 30;j++) {
			if (mp.find((1ll << j) - a) != mp.end()) ans += mp[(1 << j) - a];
		}
		mp[a]++;
		cout << ans << '\n';
	}
}

