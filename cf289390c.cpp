#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
struct DSU {
	int n;
	vector<int> p;
	vector<int> sz;
	vector<int> sum;
	vector<int> diff;
	DSU(int n = 0) {
		init(n);
	}
	void init(int x) {
		p.resize(x);
		sz.assign(x, 1);
		sum.assign(x, 0);
		diff.assign(x, 0);
		for (int i = 0;i < x;i++) p[i] = i;
	}
	int find(int x) {
		if (p[x] == x) return x;
		int pa = p[x];
		int root = find(pa);
		diff[x] += diff[pa];
		p[x] = root;
		return root;
	}
	void unite(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		p[b] = a;
		diff[b] = sum[b] - sum[a];
		sz[a] += sz[b];
	}
	void add(int x, int v) {
		sum[find(x)] += v;
	}
	void get(int x) {
		cout << sum[find(x)] + diff[x] << '\n';
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
		else if (s == "join") {
			cin >> b;
			dsu.unite(a - 1, b - 1);
		}
		else {
			cin >> b;
			dsu.add(a - 1, b);
		}
	}
}
