#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
struct DSU {
	vector<int> sz, p;
	DSU(int n = 0) {init(n);}
	void init(int x) {
		p.resize(x);
		sz.assign(x, 1);
		for (int i = 0;i < x;i++) p[i] = i;
	}
	int find(int x) {
		return (p[x] == x ? x : find(p[x]));
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
	IO
	int n, m;
	cin >> n >> m;
	DSU dsu(n);
	while (m--) {
		int t, x, y;
		cin >> t;
		if (t == 1) {
			cin >> x >> y;
			dsu.unite(x - 1, y - 1);
		}
		if (t == 2) {
			cin >> x >> y;
			cout << (dsu.find(x - 1) == dsu.find(y - 1) ? "Yes\n" : "No\n");
		}
		if (t == 3) {
			cin >> x;
			cout << dsu.sz[dsu.find(x - 1)] << '\n';
		}
	}
}
