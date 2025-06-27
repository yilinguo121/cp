#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, q;
	cin >> n >> q;
	multiset<int> st[n + 1];
	map<int, set<int>> mp;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int i, j;
			cin >> i >> j;
			st[j].insert(i);
			mp[i].insert(j);
		}
		if (type == 2) {
			int i;
			cin >> i;
			for (auto k = st[i].begin();k != st[i].end();k++) cout << *k << ' ';
			cout << '\n';
		}
		if (type == 3) {
			int i;
			cin >> i;
			for (auto k = mp[i].begin();k != mp[i].end();k++) cout << *k << ' ';
			cout << '\n';
		}
	}
}

