#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
struct DSU {
	int n;
	vector<int> p;
	vector<int> sz;
	vector<int> mx;
	vector<int> mn;
	DSU(int n = 0) {
		init(n);
	}
	void init(int x) {
		p.resize(x);
		sz.assign(x, 1);
		mx.assign(x, 0);
		mn.assign(x, INF);
		for (int i = 0;i < x;i++) p[i] = i, mn[i] = i, mx[i] = i;
	}
	int find(int x) {
		if (p[x] == x) return x;
		return find(p[x]);
	}
	bool same(int a, int b) {
		return find(a) == find(b);
	}
	void unite(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		p[b] = a;
		mx[a] = max(mx[a], mx[b]);
		mn[a] = min(mn[a], mn[b]);
		sz[a] += sz[b];
	}
	void get(int x) {
		x = find(x);
		cout << mn[x] + 1 << ' ' << mx[x] + 1 << ' ' << sz[x] << '\n';
	}
};
int main() {
	IO
	int n, m;
	cin >> n >> m;
	DSU dsu(n);
	while (m--) {
		string s;
		int a, b;
		cin >> s >> a;
		if (s == "get") {
			dsu.get(a - 1);
		}
		else {
			cin >> b;
			dsu.unite(a - 1, b - 1);
		}
	}
}
