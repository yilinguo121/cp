#include<bits/stdc++.h>
using namespace std;
int sz[1000005], p[1000005], mx = 1;
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
	mx = max(mx, sz[pa]);
	p[pb] = pa;
}
int main() {
	int n;
	while (cin >> n) {
		mx = 1;
		set<int> st;
		for (int i = 1;i <= n;i++) {
			sz[i] = 1;
			p[i] = -1;
		}
		for (int i = 1;i <= n;i++) {
			int t;
			cin >> t;
			Union(i, t);
		}
		for (int i = 1;i <= n;i++) {
			st.insert(find(i));
		}
		cout << st.size() << ' ' << mx << '\n';
	}
}
