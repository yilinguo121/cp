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
signed main() {
	int n, m, q, id = 1;
	cin >> n >> m >> q;
	vector<tuple<int, int, int, int>> v(m);
	vector<int> a(n + 1);
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (auto &[u, v, w, i] : v) {
		cin >> u >> v >> w;
		i = id++;
	}
	sort(v.begin(), v.end(), cmp);
	DSU dsu(n + 1);
	vector<pair<unsigned long long, unsigned long long>> used;
	for (auto [u, v, w, i] : v) {
		if (dsu.unite(u, v)) used.push_back({i, w});
	}
	sort(used.begin(), used.end());
	unsigned long long h = 0, sum = 0;
	for (auto [e, w] : used) {
		unsigned long long x = (e << 32) ^ w;
		h = h ^ x;
		h = (h << 1) | (h >> 63);
		sum += e;
	}
	cout << sum << ' ' << h << '\n';
}
