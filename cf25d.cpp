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
	int n;
	cin >> n;
	DSU dsu(n);
	vector<pair<int, int>> rm, add;
	for (int i = 1;i < n;i++) {
		int a, b;
		cin >> a >> b;
		if (dsu.find(a - 1) == dsu.find(b - 1)) rm.push_back({a, b});
		dsu.unite(a - 1, b - 1);
	}
	int last = -1;
	set<int> st;
	for (int i = 0;i < n;i++) st.insert(dsu.find(i));
	for (auto x : st) {
		if (last != -1) add.push_back({last + 1, x + 1});
		last = x;
	}
	cout << rm.size() << '\n';
	for (int i = 0;i < rm.size();i++) {
		cout << rm[i].first << ' ' << rm[i].second << ' ' << add[i].first << ' ' << add[i].second << '\n';
	}
}
