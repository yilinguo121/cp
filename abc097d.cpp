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
		sz[a] += b;
	}
};
int main() {
	int n, m;
	cin >> n >> m;
	DSU dsu(n);
	vector<int> v(n);
	for (auto &x : v) cin >> x, x--;
	while (m--) {
		int a, b;
		cin >> a >> b;
		dsu.unite(a - 1, b - 1);
	}
	int ans = 0;
	for (int i = 0;i < n;i++) {
		if (dsu.find(i) == dsu.find(v[i])) ans++;
	}
	cout << ans;
}
