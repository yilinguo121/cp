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
	int n, m;
	cin >> n >> m;
	DSU dsu(n);
	while (m--) {
		int k;
		cin >> k;
		int last = -1, x;
		for (int i = 0;i < k;i++) {
			cin >> x;
			if (last != -1) dsu.unite(last - 1, x - 1);
			last = x;
		}
	}
	for (int i = 0;i < n;i++) cout << dsu.sz[dsu.find(i)] << ' ';
}
