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
		for (int i = 0;i < n;i++) p[i] = i;
	}
	int find(int x) {
		if (p[x] == x) return x;
		return find(p[x]);
	}
};
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n);
	for (auto &t : v) {
		int k;
		cin >> k;
		t.resize(k);
		for (auto &x : t) cin >> x;
	}

}
