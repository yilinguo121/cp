#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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
		if (p[x] == x) return x;
		return find(p[x]);
	}
	void unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		p[b] = a;
		sz[a] += sz[b];
	}
};
int main() {
	int n;
	while (cin >> n) {
		DSU dsu(n);
		vector<int> v(n), w(n);
		for (auto &x : v) cin >> x;
		for (auto &y : w) cin >> y;
		for (int i = 1;i <= n;i++) if (v[i - 1] != i) dsu.unite(v[i - 1] - 1, i - 1);
		vector<int> a;
		for (int i = 0;i < n;i++) if (i == dsu.p[i]) a.push_back(dsu.sz[i]);
		int ans = 0;
		for (auto x : a) ans += (x - 1) * 2;
		cout << ans << '\n';
	}
}

