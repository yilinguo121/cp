#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	IO
	priority_queue<int, vector<int>, greater<int>> q;
	int n, m;
	cin >> n >> m;
	while (n--) {
		int x;
		cin >> x;
		q.push(x);
	}
	while (m--) {
		int t, x;
		cin >> t;
		if (!t) cout << q.top() << '\n';
		if (t == 1) {
			x = q.top();
			q.pop();
			cout << q.top() << '\n';
			q.push(x);
		}
		if (t == 2) {
			q.pop();
		}
		if (t == 3) {
			cin >> x;
			q.push(x);
		}
	}
}

