#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	list<int> ls;
	int t;
	cin >> t;
	while (t--) {
		int type, n, a;
		cin >> type;
		if (type == 1) {
			cin >> n;
			ls.push_front(n);
		}
		if (type == 2) {
			cin >> n;
			ls.push_back(n);
		}
		if (type == 3) {
			cin >> n >> a;
			bool flag = 1;
			for (auto it = ls.begin();it != ls.end();it++) {
				if (*it == a) {
					flag = 0;
					ls.insert(it, n);
					break;
				}
			}
			if (flag) cout << "peko\n";
		}
		if (type == 4) {
			cin >> n >> a;
			bool flag = 1;
			for (auto it = ls.begin();it != ls.end();it++) {
				if (*it == a) {
					flag = 0;
					it++;
					ls.insert(it, n);
					break;
				}
			}
			if (flag) cout << "peko\n";
		}
		if (type == 5) {
			cin >> a;
			bool flag = 1;
			if (ls.empty()) {
				cout << "peko\n";
				continue;
			}
			auto it = ls.begin();
			if (*it == a) {
				cout << "NULL\n";
				flag = 0;
			}
			it++;
			for (;it != ls.end();it++) {
				if (*it == a) {
					flag = 0;
					cout << *prev(it) << '\n';
					break;
				}
			}
			if (flag) cout << "peko\n";
		}
		if (type == 6) {
			cin >> a;
			bool flag = 1;
			if (ls.empty()) {
				cout << "peko\n";
				continue;
			}
			if (*ls.rbegin() == a) {
				cout << "NULL\n";
				flag = 0;
				continue;
			}
			for (auto it = ls.begin();it != ls.end();it++) {
				if (*it == a) {
					flag = 0;
					it++;
					cout << *it << '\n';
					break;
				}
			}
			if (flag) cout << "peko\n";
		}
		if (type == 7) {
			cin >> a;
			bool flag = 1;
			for (auto it = ls.begin();it != ls.end();it++) {
				if (*it == a) {
					flag = 0;
					ls.erase(it);
					break;
				}
			}
			if (flag) cout << "peko\n";
		}
	}
}

