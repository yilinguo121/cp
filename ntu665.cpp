#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	IO
	deque<int> d;
	int n;
	cin >> n;
	while (n--) {
		int type, x;
		cin >> type;
		if (type == 1) {
			cin >> x;
			d.push_back(x);
		}
		if (type == 2) {
			cin >> x;
			d.push_front(x);
		}
		if (type == 3) {
			if (d.empty()) cout << "error\n";
			else cout << d.back() << '\n';
		}
		if (type == 4) {
			if (d.empty()) cout << "error\n";
			else cout << d.front() << '\n';
		}
		if (type == 5) {
			if (d.empty()) cout << "error\n";
			else d.pop_back();
		}
		if (type == 6) {
			if (d.empty()) cout << "error\n";
			else d.pop_front();
		}
		if (type == 7) cout << d.size() << '\n';
	}
}

