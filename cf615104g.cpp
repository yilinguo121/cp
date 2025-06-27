#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<vector<int>> v(n + 1);
		for (auto &x : a) cin >> x;
		n--;
		while (n--) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		queue<tuple<int, int, bool>> q;
		vector<int> ans(n + 1, -1);
		while (!q.empty()) {
			auto [x, cnt, flag] = q.front();
			q.pop();
			for (auto nx : v[x]) {
				ans[nx] = max(ans[nx], ans[x] + (flag ? a[nx] : -a[nx]));
				q.push({nx, ans[x] + (flag ? a[nx] : -a[nx]), !flag});
			}
		}
		for (int i = 1;i <= n;i++) cout << ans[i] << ' ';
		cout << '\n';
	}
}
