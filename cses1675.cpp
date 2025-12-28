#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
struct DSU {
	vector<int> p, sz;
	DSU (int n = 0) {init(n);}
	void init(int x) {
		p.resize(x);
		sz.assign(x, 1);
		for (int i = 0;i < x;i++) p[i] = i;
	}
	int find(int x) {
		return (p[x] == x ? x : p[x] = find(p[x]));
	}
	bool unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return 0;
		if (sz[a] < sz[b]) swap(a, b);
		p[b] = a;
		sz[a] += sz[b];
		return 1;
	}
};
signed main() {
	IO
	int n, m;
	cin >> n >> m;
	DSU dsu(n);
	vector<tuple<int, int, int>> v(m);
	for (auto &[w, a, b] : v) {
		cin >> a >> b >> w;
		a--, b--;
	}
	int cnt = 0, root = 0;
	sort(v.begin(), v.end());
	for (auto [w, a, b] : v) if (dsu.unite(a, b)) cnt += w;
	for (int i = 0;i < n;i++) if (dsu.p[i] == i) root++;
	if (root == 1) cout << cnt;
	else cout << "IMPOSSIBLE";
}
