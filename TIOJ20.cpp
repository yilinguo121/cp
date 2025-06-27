#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	IO
	int n;
	cin >> n;
	list<int> ls;
	map<int, list<int>::iterator> mp;
	for (int i = 1;i <= n;i++) mp[i] = ls.insert(ls.end(), i);
	int m;
	cin >> m;
	while (m--) {
		int t, x;
		cin >> t >> x;
		if (!t) ls.erase(mp[x]);
		else {
			if (mp[x] == ls.begin()) continue;
			auto it = ls.insert(prev(mp[x]), x);
			ls.erase(mp[x]);
			mp[x] = it;
		}
	}
	for (auto x : ls) cout << x << ' ';
}

