#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
vector<bool> vis(10000000);
queue<int> q;
int f(int t) {
	int x = 1;
	while (t--) {
		x *= 10;
	}
	return x;
}
signed main() {
	int a, n;
	cin >> a >> n;
	int n_sz = f(to_string(n).size());
	q.push(1);
	vis[1] = 1;
	int ans = 0;
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			int x = q.front();
			q.pop();
			if (x == n) {
				cout << ans;
				return 0;
			}
			if (x * a < n_sz and !vis[x * a]) {
				q.push(x * a);
				vis[x * a] = 1;
			}
			if (x % 10 and x >= 10 and !vis[stoi(to_string(x % 10) + to_string(x / 10))]) {
				q.push(stoi(to_string(x % 10) + to_string(x / 10)));
				vis[stoi(to_string(x % 10) + to_string(x / 10))] = 1;
			}
		}
		ans++;
	}
	cout << "-1";
}
