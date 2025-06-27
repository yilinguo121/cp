#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	IO
	int n, m;
	cin >> n >> m;
	vector<list<int>> v(n);
	while (m--) {
		int i, j, x;
		string s;
		cin >> s;
		if (s == "ADD") {
			cin >> i >> x;
			v[i - 1].push_back(x);
		}
		if (s == "LEAVE") {
			cin >> i;
			if (v[i - 1].empty()) cout << "queue " << i << " is empty!\n";
			else v[i - 1].pop_front();
		}
		if (s == "JOIN") {
			cin >> i >> j;
			v[j - 1].splice(v[j - 1].end(), v[i - 1]);
			v[i - 1].clear();
		}
	}
	for (int i = 1;i <= n;i++) {
		cout << "queue " << i << ": ";
		if (v[i - 1].empty()) cout << "empty";
		else {
			for (auto it = v[i - 1].begin();it != v[i - 1].end();it++) {
				cout << *it << ' ';
			}
		}
		cout << '\n';
	}
}

