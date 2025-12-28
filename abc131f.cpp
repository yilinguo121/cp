#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
struct DSU {
	vector<int> p, x, y;
	DSU (int n = 0) {init(n);}
	void init(int t) {
		p.resize(t);
		x.resize(200000);
		y.resize(200000);
		for (int i = 0;i < t;i++) p[i] = i;
		for (int i = 0;i < 200000;i++) {
			x[i] = (i < 100000);
			y[i] = (i >= 100000);
		}
	}
	int find(int x) {
		return (p[x] == x ? x : p[x] = find(p[x]));
	}
	int unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return 0;
		int now = x[a] * y[b] + x[b] * y[a];
		p[b] = a;
		x[a] += x[b];
		y[a] += y[b];
		return now;
	}
};
signed main() {
	int n;
	cin >> n;
	DSU dsu(200000);
	int ans = 0;
	while (n--) {
		int a, b;
		cin >> a >> b;
		ans += dsu.unite(a - 1, b - 1 + 100000) - 1;
	}
	cout << ans;
}
