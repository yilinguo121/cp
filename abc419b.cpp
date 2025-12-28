#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	priority_queue<int, vector<int>, greater<int>> q;
	while (t--) {
		int type, x;
		cin >> type;
		if (type == 1) {
			cin >> x;
			q.push(x);
		}
		else {
			cout << q.top() << '\n';
			q.pop();
		}
	}
}

