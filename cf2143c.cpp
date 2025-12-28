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
		vector<vector<int>> v(n + 1);
		vector<int> cnt(n + 1);
		for (int i = 0;i < n - 1;i++) {
			int a, b, x, y;
			cin >> a >> b >> x >> y;
			if (x > y) {
				v[b].push_back(a);
				cnt[a]++;
			}
			else {
				v[a].push_back(b);
				cnt[b]++;
			}
		}
		queue<int> q;
		for (int i = 1;i <= n;i++) if (!cnt[i]) q.push(i);
		vector<int> a;
		while (!q.empty()) {
			auto t = q.front();
			q.pop();
			a.push_back(t);
			for (auto nt : v[t]) {
				if (!--cnt[nt]) q.push(nt);
			}
		}
		vector<int> ans(n);
		for (int i = 0;i < n;i++) ans[a[i] - 1] = i + 1;
		for (auto x : ans) cout << x << ' ';
		cout << '\n';
	}
}
