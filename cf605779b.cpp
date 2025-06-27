#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	IO
	int q;
	cin >> q;
	list<string> ls = {"ButterFly"};
	auto it = ls.begin();
	while (q--) {
		string type, n;
		cin >> type;
		if (type == "ADD_LEFT") {
			cin >> n;
			ls.insert(it, n);
		}
		if (type == "ADD_RIGHT") {
			cin >> n;
			ls.insert(next(it), n);
		}
		if (type == "PLAY_NEXT") {
			int k;
			cin >> k;
			k %= ls.size();
			while (k--) {
				it++;
				if (it == ls.end()) it = ls.begin();
			}
		}
		if (type == "PLAY_PREV") {
			int k;
			cin >> k;
			k %= ls.size();
			while (k--) {
				if (it == ls.begin()) it = prev(ls.end());
				else it--;
			}
		}
		if (type == "DELETE") {
			auto x = it;
			it++;
			if (it == ls.end()) it = ls.begin();
			ls.erase(x);
		}
		if (type == "CURR") cout << *it << '\n';
	}
}

