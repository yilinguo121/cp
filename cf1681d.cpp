#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
signed main() {
	IO
	int n, x;
	cin >> n >> x;
	queue<int> q;
	map<int, bool> vis;
	q.push(x);
	vis[x] = 1;
	if (to_string(x).size() == n) {
		cout << 0;
		return 0;
	}
	int ans = 1;
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			map<int, int> mp;
			int t = q.front();
			q.pop();
			for (auto s : to_string(t)) mp[s - '0']++;
			for (int i = 2;i <= 9;i++) {
				if (mp[i] and !vis[i * t]) {
					if (to_string(i * t).size() == n) {
						cout << ans;
						return 0;
					}
					q.push(i * t);
					vis[i * t] = 1;
				}
			}
		}
		ans++;
	}
	cout << -1;
}
