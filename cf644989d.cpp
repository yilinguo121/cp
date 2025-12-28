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
		return (p[x] == x ? x : p[x] = find(p[x]));
	}
	bool unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return 0;
		if (sz[a] < sz[b]) swap(a, b);
		p[b] = a;
		sz[a] += sz[b];
		return 1;
	}
};
vector<tuple<long long, int, int>> a;
vector<pair<int, int>> v;
vector<long long> ans;
int main() {
	IO;
	int n;
	cin >> n;
	v.resize(n);
	DSU dsu(n);
	for (auto &[x, y] : v) cin >> x >> y;
	for (int i = 0;i < n;i++) {
		for (int j = i + 1;j < n;j++) {
			a.push_back({(1ll * v[i].first - v[j].first) * (1ll * v[i].first - v[j].first) + (1ll * v[i].second - v[j].second) * (1ll * v[i].second - v[j].second), i, j});
		}
	}
	sort(a.begin(), a.end());
	for (auto [w, x, y] : a) if (dsu.unite(x, y)) ans.push_back(w);
	reverse(ans.begin(), ans.end());
	for (auto x : ans) cout << x << '\n';
}
