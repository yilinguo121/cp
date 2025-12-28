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
		if (x == p[x]) return x;
		return find(p[x]);
	}
	void unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		p[b] = a;
	}
};
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		DSU dsu(n);
		vector<int> v(n);
		for (int i = 0;i < n;i++) {
			cin >> v[i];
			dsu.unite(v[i] - 1, i);
		}
		for (int i = 0;i < n;i++) cout << dsu.sz[dsu.find(i)] << ' ';
		cout << '\n';
	}
}

