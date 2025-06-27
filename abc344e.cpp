#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int n;
	cin >> n;
	list<int> ls;
	map<int, list<int>::iterator> mp;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		mp[x] = ls.insert(ls.end(), x);
	}
	int q;
	cin >> q;
	while (q--) {
		int type, i, j;
		cin >> type;
		if (type == 1) {
			cin >> i >> j;
			mp[j] = ls.insert(next(mp[i]), j);
		}
		else {
			cin >> i;
			ls.erase(mp[i]);
		}
	}
	for (auto x : ls) cout << x << ' ';
}

