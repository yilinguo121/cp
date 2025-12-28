#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<int> v;
int ans = INF, n, a, b, c;
void dfs(int id, int x, int y, int z, int cnt) {
	if (id == n) {
		if (x and y and z) ans = min(ans, abs(x - a) + abs(y - b) + abs(z - c) + cnt);
		return;
	}
	dfs(id + 1, x + v[id], y, z, cnt + (x != 0) * 10);
	dfs(id + 1, x, y + v[id], z, cnt + (y != 0) * 10);
	dfs(id + 1, x, y, z + v[id], cnt + (z != 0) * 10);
	dfs(id + 1, x, y, z, cnt);
}
int main() {
	cin >> n >> a >> b >> c;
	v.resize(n);
	for (auto &x : v) cin >> x;
	dfs(0, 0, 0, 0, 0);
	cout << ans;
}

