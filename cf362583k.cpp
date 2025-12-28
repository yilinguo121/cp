#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int n, sum = 0;
		cin >> n;
		vector<int> v(n);
		for (auto &x : v) {
			cin >> x;
			sum += x;
		}
		if (sum != 2 * (n - 1)) {
			cout << "NO\n";
			continue;
		}
		queue<int> q;
		for (int i = 0;i < n;i++) {
			if (v[i] == 1) q.push(i);
		}
		auto now = v;
		vector<pair<int, int>> ans;
		for (int i = 0;i < n;i++) {
			for (int cnt = 1;cnt < v[i];cnt++) {
				int j = q.front();
				q.pop();
				ans.push_back({i, j});
				if (--now[i] == 1) q.push(i);
			}
		}
		int x = q.front();
		q.pop();
		ans.push_back({x, q.front()});
		cout << "YES\n" << ans.size() << '\n';
		for (auto [x, y] : ans) cout << x + 1 << ' ' << y + 1 << '\n';
	}
}

