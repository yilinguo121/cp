#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
struct DSU {
	vector<int> sz, p, c, pw;
	DSU(int n = 0) { init(n); }
	void init(int x) {
		p.resize(x);
		sz.assign(x, 1);
		c.assign(x, 0);
		pw.assign(x, 0);
		for (int i = 0;i < x;i++) p[i] = i;
	}
	int find(int x) {
		if (p[x] == x) return x;
		return find(p[x]);
	}
	int unite(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return 0;
		long long bef = 0;
		if (pw[a] > 0) bef += c[a];
		if (pw[b] > 0) bef += c[b];
		if (sz[a] < sz[b]) swap(a, b);
		p[b] = a;
		sz[a] += sz[b];
		c[a] += c[b];
		pw[a] += pw[b];
		long long aft = 0;
		if (pw[a] > 0) aft += c[a];
		return aft - bef;
	}
};
signed main() {
	IO;
	int n, m, e;
	cin >> n >> m >> e;
	DSU dsu(n + m);
	vector<pair<int, int>> v(e);
	for (auto &[x, y] : v) {
		cin >> x >> y;
		x--, y--;
	}
	int q;
	cin >> q;
	vector<int> x(q);
	vector<bool> rem(e, 0);
	for (int i = 0;i < q;i++) {
		cin >> x[i];
		x[i]--;
		rem[x[i]] = 1;
	}
	for (int i = 0;i < n;i++) dsu.c[i] = 1;
	for (int i = n;i < n + m;i++) dsu.pw[i] = 1;
	int now = 0;
	for (int i = 0; i < e; i++) {
		if (!rem[i]) now += dsu.unite(v[i].first, v[i].second);
	}
	vector<int> ans(q);
	for (int i = q - 1;i >= 0;i--) {
		ans[i] = now;
		now += dsu.unite(v[x[i]].first, v[x[i]].second);
	}
	for (auto x : ans) cout << x << '\n';
}
