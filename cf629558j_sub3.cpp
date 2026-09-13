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
bool cmp(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
	auto [u1, v1, w1, i1] = a;
	auto [u2, v2, w2, i2] = b;
	if (w1 == w2) return i1 < i2;
	else return w1 < w2;
}
vector<vector<pair<int, int>>> adj;
vector<int> pa, a;
void dfs_pa(int u, int p) {
	pa[u] = p;
	for (auto [v, w] : adj[u]) {
		if (v == p) continue;
		dfs_pa(v, u);
	}
}
long long dfs_sum(int u) {
	long long s = a[u];
	for (auto [v, w] : adj[u]) {
		if (v == pa[u]) continue;
		s += dfs_sum(v);
	}
	return s;
}
signed main() {
	IO
	int n, m, q;
	cin >> n >> m >> q;
	a.assign(n + 1, 0);
	for (int i = 1;i <= n;i++) cin >> a[i];
	vector<tuple<int, int, int, int>> e(m);
	for (int i = 0;i < m;i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[i] = {u, v, w, i + 1};
	}
	sort(e.begin(), e.end(), cmp);
	DSU dsu(n + 1);
	vector<pair<unsigned long long, unsigned long long>> used;
	adj.assign(n + 1, {});
	for (auto [u, v, w, id] : e) {
		if (dsu.unite(u, v)) {
			used.push_back({(unsigned long long)id, (unsigned long long)w});
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}
	}
	sort(used.begin(), used.end());
	unsigned long long h = 0, s = 0;
	for (auto [id, w] : used) {
		unsigned long long x = (id << 32) ^ w;
		h ^= x;
		h = (h << 1) | (h >> 63);
		s += id;
	}
	cout << s << ' ' << h << '\n';
	pa.assign(n + 1, 0);
	dfs_pa(1, 0);
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int u, x;
			cin >> u >> x;
			a[u] += x;
		}
		else if (type == 2) {
			int u;
			cin >> u;
			cout << dfs_sum(u) << '\n';
		}
	}
}
