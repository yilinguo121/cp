#include <bits/stdc++.h>
using namespace std;
int main() {
	int q;
	cin >> q;
	map<int, int> mp;
	while (q--) {
		int t, x;
		cin >> t >> x;
		if (t == 1) mp[x]++;
		if (t == 2) mp[x] = max(0, mp[x] - 1);
		if (t == 3) cout << mp[x] << '\n';
	}
}

