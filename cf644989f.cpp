#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
struct DSU {
	vector<int> p, sz;
	int root;
	DSU (int n = 0) {init(n);}
	void init(int x) {
		root = x;
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
		root--;
		return 1;
	}
};
vector<tuple<long long, int, int>> a;
vector<long long> ans;
int main() {
	IO;
	int n, m;
	cin >> n >> m;
	DSU dsu(n);
	a.resize(m);
	for (auto &[w, x, y] : a) {
		cin >> x >> y >> w;
		x--, y--;
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	for (auto [w, x, y] : a) {
		x = dsu.find(x), y = dsu.find(y);
		if (x == y) continue;
		if (dsu.root == 3) {
			cout << w;
			return 0;
		}
		dsu.unite(x, y);
	}
	cout << 0;
}
