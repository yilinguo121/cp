#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	queue<int> q;
	int n;
	cin >> n;
	while (n--) {
		int type, x;
		cin >> type;
		if (type == 1) {
			cin >> x;
			q.push(x);
		}
		if (type == 2) {
			if (q.empty()) cout << "QQ\n";
			else q.pop();
		}
		if (type == 3) {
			if (q.empty()) cout << "QQ\n";
			else cout << q.front() << '\n';
		}
		if (type == 4) cout << q.size() << '\n';
	}
}

