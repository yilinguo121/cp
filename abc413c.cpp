#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	queue<pair<int, int>> q;
	int n;
	cin >> n;
	while (n--) {
		int type, x, y;
		cin >> type >> x;
		if (type == 1) {
			cin >> y;
			q.push({y, x});
		}
		else {
			int cnt = 0;
			while (x > 0) {
				int t = min(x, q.front().second);
				cnt += t * q.front().first;
				if (q.front().second == t) q.pop();
				else q.front().second -= t;
				x -= t;
			}
			cout << cnt << '\n';
		}
	}
}

