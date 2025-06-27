#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	IO
	int n;
	cin >> n;
	list<int> ls;
	vector<list<int>::iterator> pos(n + 1);
	for (int i = 1;i <= n;i++) pos[i] = ls.insert(ls.end(), i);
	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		ls.erase(pos[b]);
		pos[b] = ls.insert(pos[a], b);
	}
	for (auto x : ls) cout << x << '\n';
}

