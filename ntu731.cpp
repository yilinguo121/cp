#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n, x;
	cin >> n;
	if (n == 1) {
		cin >> x;
		cout << x;
		return 0;
	}
	priority_queue<int, vector<int>, greater<int>> q;
	while (n--) {
		cin >> x;
		q.push(x);
	}
	int ans = 0;
	while (q.size() >= 2) {
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		ans += a + b;
		q.push(a + b);
	}
	cout << ans;
}
