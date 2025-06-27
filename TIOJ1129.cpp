#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	IO
	int a, b, c;
	while (cin >> a >> b >> c) {
		vector<int> x(b), y(b);
		x[0] = (269 * a + 11) % 103;
		y[0] = (271 * a + 13) % 97;
		for (int i = 1;i < b;i++) {
			x[i] = (269 * x[i - 1] + 11) % 103;
			y[i] = (271 * y[i - 1] + 13) % 97;
		}
		bitset<4000> vis;
		vector<int> ans;
		for (int i = 0;i < b;i++) {
			if (vis[i]) continue;
			queue<int> q;
			q.push(i);
			vis[i] = 1;
			int cnt = 0;
			while (!q.empty()) {
				int t = q.front();
				q.pop();
				cnt++;
				for (int j = 0;j < b;j++) {
					if (vis[j]) continue;
					if ((x[j] - x[t]) * (x[j] - x[t]) + (y[j] - y[t]) * (y[j] - y[t]) <= c * c) {
						q.push(j);
						vis[j] = 1;
					}
				}
			}
			ans.push_back(cnt);
		}
		cout << ans.size() << '\n';
		sort(ans.begin(), ans.end());
		for (auto v : ans) cout << v << ' ';
		cout << '\n';
	}
}
	
