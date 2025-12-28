#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	priority_queue<int> q;
	int n, m;
	cin >> n >> m;
	while (n--) {
		int x;
		cin >> x;
		q.push(x);
	}
	long long sum = 0;
	while (m--) {
		sum += q.top();
		q.pop();
	}
	cout << sum;
}

