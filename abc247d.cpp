#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	queue<pair<int, int>> q;
	int n;
	cin >> n;
	while (n--) {
		int t, x, y;
		cin >> t;
		if (t == 1) {
			cin >> x >> y;
			q.push({x, y});
		}
		else {
			long long cnt = 0;
			cin >> x;
			while (x) {
				int k = min(q.front().second, x);
				x -= k;
				cnt += 1ll * q.front().first * k;
				if (k == q.front().second) q.pop();
				else q.front().second -= k;
			}
			cout << cnt << '\n';
		}
	}
}

