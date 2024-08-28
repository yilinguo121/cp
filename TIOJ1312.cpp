#include<bits/stdc++.h>
using namespace std;
int p[10005] = {}, sz[10005] = {};
int find(int x) {
	if (p[x] == -1) return x;
	p[x] = find(p[x]);
	return p[x];
}
void f(int a, int b) {
	int pa = find(a), pb = find(b);
	if (pa == pb) return;
	if (sz[pa] < sz[pb]) swap(pa, pb);
	sz[pa] += sz[pb];
	p[pb] = pa;
}
int main() {
	int n, m;
	while(cin >> n >> m) {
		for (int i = 1;i <= n;i++) {
			p[i] = -1;
			sz[i] = 1;
		}
		for (int i = 0;i < m;i++) {
			int a, b;
			cin >> a >> b;
			f(a, b);
		}
		int k;
		cin >> k;
		int pk = find(k);
		for (int i = 1;i <= n;i++) {
			if (find(i) == pk) {
				cout << i << '\n';
				break;
			}
		}
	}
}
