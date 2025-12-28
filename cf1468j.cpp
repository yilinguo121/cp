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
	IO;
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		DSU dsu(n);
		vector<tuple<int, int, int>> v(m);
		for (auto &[w, x, y] : v) cin >> x >> y >> w;
		sort(v.begin(), v.end());
		int ans = 0;
		bool flag = 1;
		for (auto [w, x, y] : v) if (dsu.unite(x - 1, y - 1) and w - k >= 0) {
			flag = 0;
			ans += w - k;
		}
		int t = INF;
		if (flag) for (auto [w, x, y] : v) t = min(t, abs(w - k));
		cout << (t == INF ? ans : ans + t) << '\n';
	}
}
