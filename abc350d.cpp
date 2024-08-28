#include<bits/stdc++.h>
using namespace std;
int sz[200005], p[200005];
int find(int x) {
	if (p[x] == -1) return x;
	p[x] = find(p[x]);
	return p[x];
}
void Union(int a, int b) {
	int pa = find(a), pb = find(b);
	if (pa == pb) return;
	if (sz[pa] > sz[pb]) swap(pa, pb);
	sz[pa] += sz[pb];
	p[pb] = pa;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		sz[i] = 1;
		p[i] = -1;
	}
	for (int i = 1;i <= m;i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}
	int v[200005] = {};
	long long ans = 0;
	for (int i = 1;i <= n;i++) {
		int f = find(i);
		if (v[f]) continue;
		v[f]++;
		ans += (1ll * (sz[f] - 1) * sz[f]) / 2;
	}
	cout << ans - m;
}

