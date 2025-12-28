#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k, x;
		cin >> n >> k >> x;
		priority_queue<float> q;
		for (int i = 0;i < n;i++) {
			float a;
			cin >> a;
			q.push(a);
		}
		while (k--) {
			q.push(q.top() / 2);
			q.push(q.top() / 2);
			q.pop();
		}
		x--;
		while (x--) q.pop();
		cout << fixed << setprecision(15) << q.top() << '\n';
	}
}
