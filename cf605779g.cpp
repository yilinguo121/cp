#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
priority_queue<int> q1, q2;
int n, m, k, x;
int ans = 0;
void f(int t) {
	q1.push(t);
	if (q1.size() >= k) {
		ans += q1.top();
		q2.push(q1.top());
		q1.pop();
	}
	if (q2.size() > x) {
		ans -= q2.top();
		q2.pop();
	}
}
signed main() {
	IO
	cin >> n >> m >> x >> k;
	for (int i = 0;i < n;i++) {
		int t;
		cin >> t;
		f(t);
	}
	cout << ans << '\n';
	for (int i = 0;i < m;i++) {
		int t;
		cin >> t;
		f(t);
		cout << ans << '\n';
	}

}

