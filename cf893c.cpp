#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
struct DSU {
	vector<int> p, v, sz;
	DSU(int n = 0) {init(n);}
	void init(int x) {
		p.resize(x);
		v.resize(x);
		sz.assign(x, 1);
		for (int i = 0;i < x;i++) p[i] = i;
	}
	int find(int x) {
		if (x == p[x]) return x;
		return find(p[x]);
	}
	void unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		p[b] = a;
		sz[a] += sz[b];
		v[a] = min(v[a], v[b]);
	}
};
signed main() {
	IO
	int n, m;
	cin >> n >> m;
	DSU dsu(n);
	for (int i = 0;i < n;i++) cin >> dsu.v[i];
	while (m--) {
		int a, b;
		cin >> a >> b;
		dsu.unite(a - 1, b - 1);
	}
	set<int> st;
	for (int i = 0;i < n;i++) if (i == dsu.p[i]) st.insert(i);
	int ans = 0;
	for (auto x : st) ans += dsu.v[x];
	cout << ans;
}
