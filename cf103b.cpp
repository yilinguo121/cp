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
	bool ans = 1;
	cin >> n >> m;
	DSU dsu(n);
	if (n < 3 or n != m) ans = 0;
	while (m--) {
		int a, b;
		cin >> a >> b;
		dsu.unite(a - 1, b - 1);
	}
	int cnt = 0;
	for (int i = 0;i < n;i++) cnt += (i == dsu.p[i]);
	cout << (cnt == 1 and ans ? "FHTAGN!" : "NO");
}
