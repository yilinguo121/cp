#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
struct DSU {
	vector<int> p, sz, v;
	DSU (int t = 0) {init(t);}
	void init(int n) {
		p.resize(n);
		v.resize(n);
		sz.assign(n, 1);
		for (int i = 0;i < n;i++) p[i] = i;
	}
	int find(int x) {return p[x] = (x == p[x] ? x : find(p[x]));}
	void unite(int b, int a) {
		a = find(a), b = find(b);
		if (a == b) return;
		sz[a] += sz[b];
		p[b] = a;
		v[b] = v[a];
	}
};
int main() {
	vector<int> h(5);
	for (auto &x : h) cin >> x;
	int n, t;
	cin >> n >> t;
	vector<int> last(n + 1, -1), ans(n + 1);
	DSU dsu(n);
	for (int i = 0;i < n;i++) {
		cin >> dsu.v[i];
		ans[dsu.v[i]]++;
		if (last[dsu.v[i]] != -1) dsu.unite(last[dsu.v[i]], i);
		last[dsu.v[i]] = i;
	}
	while (t--) {
		int type, x, y;
		cin >> type;
		if (type == 1) {
			cin >> x >> y;
			x = dsu.find(x - 1), y = dsu.find(y - 1);
			if (x == y) continue;
			ans[dsu.v[y]] += ans[dsu.v[x]];
			ans[dsu.v[x]] = 0;
			dsu.unite(x, y);
		}
		if (type == 2) {
			cin >> x >> y;
		}
		if (type == 3) {
			cin >> x >> y;
		}
		if (type == 4) {
			cin >> x;
			cout << dsu.v[dsu.find(x - 1)] << ' ' << ans[dsu.v[dsu.find(x - 1)]] << '\n';
		}
		if (type == 5) {
			cin >> x;
			cout << ans[x] << '\n';
		}
	}
	for (int i = 0;i < n;i++) cout << dsu.v[dsu.find(i)] << ' ';
}
