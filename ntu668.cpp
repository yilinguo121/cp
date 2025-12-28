#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
struct DSU {
	vector<int> p, sz;
	multiset<int> st;
	DSU (int n = 0) {init(n);}
	void init(int x) {
		p.resize(x);
		sz.assign(x, 1);
		for (int i = 0;i < x;i++) p[i] = i;
	}
	int find(int x) {
		return (x == p[x] ? x : find(p[x]));
	}
	void unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		st.erase(st.find(sz[a]));
		st.erase(st.find(sz[b]));
		sz[a] += sz[b];
		st.insert(sz[a]);
		p[b] = a;
	}
};
int main() {
	IO
	int n, k;
	cin >> n >> k;
	vector<int> v(n + 2);
	DSU dsu(n + 2);
	for (int i = 1;i <= n;i++) {
		cin >> v[i];
		if (v[i]) dsu.st.insert(1);
		if (v[i] and v[i - 1]) dsu.unite(i, i - 1);
	}
	int s = 0, t = 0;
	if (!dsu.st.empty()) {
		s += *dsu.st.rbegin();
		t += *dsu.st.begin();
	}
	while (k--) {
		int x;
		cin >> x;
		v[x] = 1;
		dsu.st.insert(1);
		if (v[x - 1]) dsu.unite(x - 1, x);
		if (v[x + 1]) dsu.unite(x, x + 1);
		if (!dsu.st.empty()) {
			s += *dsu.st.rbegin();
			t += *dsu.st.begin();
		}
	}
	cout << s << '\n' << t;
}
