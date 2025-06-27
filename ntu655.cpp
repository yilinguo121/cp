#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		map<int, int> team;
		for (int i = 1;i <= n;i++) {
			int x;
			cin >> x;
			while (x--) {
				int y;
				cin >> y;
				team[y] = i;
			}
		}
		list<deque<int>> ls;
		vector<list<deque<int>>::iterator> pos(n + 1, ls.end());
		while (q--) {
			int type, x;
			cin >> type;
			if (type == 1) {
				cin >> x;
				if (pos[team[x]] != ls.end()) pos[team[x]]->push_back(x);
				else {
					deque<int> q;
					q.push_back(x);
					pos[team[x]] = ls.insert(ls.end(), q);
				}
			}
			else {
				if (ls.empty()) cout << "-1\n";
				else {
					x = ls.begin()->front();
					cout << x << '\n';
					ls.begin()->pop_front();
					if (ls.begin()->empty()) {
						pos[team[x]] = ls.end();
						ls.pop_front();
					}
				}
			}
		}
	}
}
