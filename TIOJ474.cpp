#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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
int main() {
	IO;
	int n, m;
	cin >> n >> m;
	DSU dsu(n + 1);
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	vector<tuple<int, int, int>> v(m);
	for (auto &[w, x, y] : v) cin >> x >> y >> w;
	for (int i = 1;i <= n;i++) v.push_back({a[i - 1], 0, i});
	sort(v.begin(), v.end());
	long long ans = 0;
	for (auto [w, x, y] : v) {
		if (dsu.unite(x, y)) {
			ans += w;
			if (!--n) break;
		}
	}
	cout << ans;
}
