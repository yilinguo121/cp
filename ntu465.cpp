#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	map<int, int> mp;
	long long ans = 0;
	while (m--) {
		int type;
		cin >> type;
		if (type == 2) {
			int c;
			cin >> c;
			if (mp.find(c) != mp.end()) ans += mp[c];
			else ans += c;
		}
		else {
			int a, b;
			cin >> a >> b;
			if (mp.find(a) == mp.end()) mp[a] = a;
			if (mp.find(b) == mp.end()) mp[b] = b;
			swap(mp[a], mp[b]);
		}
	}
	cout << ans;
}

