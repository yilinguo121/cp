#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
struct DSU {
	vector<int> p;
	DSU(int n = 0) {init(n);}
	void init(int x) {
		p.resize(x);
		for (int i = 0;i < x;i++) p[i] = i;
	}
	int find(int x) {
		if (p[x] == x) return x;
		return find(p[x]);
	}
	void unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		p[a] = b;
	}
};
int main() {
	int n, k;
	cin >> n >> k;
	DSU dsu(n + 1);
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	sort(v.begin(), v.end());
	int ans = n;
	for (int j = 0;j < n;j++) {
		int i = upper_bound(v.begin(), v.end(), v[j]) - v.begin();
		i = dsu.find(i);
		if (v[i] > v[j] and v[i] <= v[j] + k and dsu.find(j) == j) {
			ans--;
			dsu.unite(j, j + 1);
		}
	}
	cout << ans;
}

