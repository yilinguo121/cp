#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(m + 1);
	for (int i = 0;i < n;i++) {
		int a, b;
		cin >> a >> b;
		int s = m - a + 1;
		if (s >= 1 and s <= m) v[s].push_back(b);
	}
	priority_queue<int> q;
	int ans = 0;
	for (int i = m;i >= 1;i--) {
		for (auto x : v[i]) q.push(x);
		if (!q.empty()) {
			ans += q.top();
			q.pop();
		}
	}
	cout << ans;
}

