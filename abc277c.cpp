#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
bitset<1000000001> vis;
int main() {
	int n;
	cin >> n;
	map<int, vector<int>> v;
	while (n--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<int> q;
	int ans = 1;
	q.push(1);
	vis[1] = 1;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		ans = max(ans, t);
		for (auto nt : v[t]) {
			if (vis[nt]) continue;
			q.push(nt);
			vis[nt] = 1;
		}
	}
	cout << ans;
}
