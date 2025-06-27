#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
int f(int n) {
	int cnt = 0;
	while (n) {
		cnt += n % 10;
		n /= 10;
	}
	return cnt;
}
signed main() {
	IO
	int n, k;
	cin >> n >> k;
	priority_queue<int> q;
	while (n--) {
		int x;
		cin >> x;
		q.push(x);
	}
	while (k--) {
		if (q.top() < 10) break;
		q.push(f(q.top()));
		q.pop();
	}
	cout << q.top();
}

