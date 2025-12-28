#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
struct DSU {
	vector<int> sz;
	vector<int> p;
	DSU(int n = 0) {init(n);}
	void init(int x) {
		p.resize(x);
		sz.assign(x, 1);
		for (int i = 0;i < x;i++) p[i] = i;
	}
	int find(int x) {
		if (p[x] == x) return x;
		return find(p[x]);
	}
	void unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		p[b] = a;
	}
};
signed main() {
	int n, m;
	cin >> n >> m;
	DSU dsu(n);
	vector<pair<int, int>> v(m);
	for (auto &[x, y] : v) {
		cin >> x >> y;
		x--, y--;
	}
	reverse(v.begin(), v.end());
	int now = n * (n - 1) / 2;
	vector<int> ans;
	for (auto [x, y] : v) {
		ans.push_back(now);
		int px = dsu.find(x), py = dsu.find(y);
		if (px == py) continue;
		now -= dsu.sz[px] * dsu.sz[py];
		dsu.unite(px, py);
	}
	reverse(ans.begin(), ans.end());
	for (auto x : ans) cout << x << '\n';
}
