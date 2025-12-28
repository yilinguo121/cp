#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<vector<int>> v;
vector<int> dis;
int bn, bl;
void dfs(int t, int p, int len) {
	dis[t] = len;
	if (len > bl or (len == bl and t > bn)) {
		bl = len;
		bn = t;
	}
	for (auto nt : v[t]) {
		if (nt != p) dfs(nt, t, len + 1);
	}
}
int main() {
	int n;
	cin >> n;
	v.resize(n + 1);
	for (int i = 1;i < n;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bn = 0, bl = -1;
	dis.assign(n + 1, -1);
	dfs(1, 0, 0);
	int s = bn;
	bn = 0, bl = -1;
	dis.assign(n + 1, -1);
	dfs(s, 0, 0);
	int t = bn;
	auto ds = dis;
	bn = 0, bl = -1;
	dis.assign(n + 1, -1);
	dfs(t, 0, 0);
	auto dt = dis;
	for (int i = 1;i <= n;i++) cout << (ds[i] == dt[i] ? max(s, t) : (ds[i] > dt[i] ? s : t)) << '\n';
}

