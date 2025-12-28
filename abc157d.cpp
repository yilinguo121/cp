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
		sz[a] += sz[b];
		p[b] = a;
	}
};
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	DSU dsu(n);
	vector<int> cnt(n);
	while (m--) {
		int a, b;
		cin >> a >> b;
		dsu.unite(a - 1, b - 1);
		cnt[a - 1]++, cnt[b - 1]++;
	}
	vector<int> ans(n);
	for (int i = 0;i < n;i++) ans[i] = dsu.sz[dsu.find(i)] - 1 - cnt[i];
	for (int i = 0;i < k;i++) {
		int a, b;
		cin >> a >> b;
		if (dsu.find(a - 1) == dsu.find(b - 1)) ans[a - 1]--, ans[b - 1]--;
	}
	for (auto x : ans) cout << x << ' ';
}
