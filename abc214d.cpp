#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
struct DSU {
	vector<int> p, sz;
	DSU(int n = 0) {init(n);}
	void init(int x) {
		p.resize(x);
		sz.assign(x, 1);
		for (int i = 0;i < x;i++) p[i] = i;
	}
	int find(int x) {
		return (x == p[x] ? x : find(p[x]));
	}
	void unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		p[b] = a;
		sz[a] += sz[b];
	}
};
signed main() {
	int n;
	cin >> n;
	vector<tuple<int, int, int>> v(n - 1);
	DSU dsu(n);
	for (auto &[w, a, b] : v) cin >> a >> b >> w;
	sort(v.begin(), v.end());
	int ans = 0;
	for (auto [w, a, b] : v) {
		a = dsu.find(a - 1), b = dsu.find(b - 1);
		if (a == b) continue;
		ans += dsu.sz[a] * dsu.sz[b] * w;
		dsu.unite(a, b);
	}
	cout << ans;
}

