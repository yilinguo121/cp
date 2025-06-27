#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int n, k;
	cin >> n >> k;
	priority_queue<int, vector<int>, greater<int>> q;
	while (n--) {
		int x;
		cin >> x;
		q.push(x);
		if (q.size() > k) q.pop();
		if (q.size() >= k) cout << q.top() << '\n';
	}
}

