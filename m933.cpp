#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int p, q, r, m;
	cin >> p >> q >> r >> m;
	vector<vector<int>> t(p + q + r + 10);
	vector<int> v(p + q + r + 10, -1), sz(p + q + r + 10), ans(p + q + r + 10);
	vector<int> a(p + q + 10);
	for (int i = 1;i <= p;i++) cin >> v[i];
	for (int i = p + 1;i <= p + q;i++) cin >> a[i];
	while (m--) {
		int a, b;
		cin >> a >> b;
		t[a].push_back(b);
		sz[b]++;
	}
	queue<int> qu;
	for (int i = 1;i <= p;i++) qu.push(i);
	while (!qu.empty()) {
		auto x = qu.front();
		qu.pop();
		for (auto nx : t[x]) {
			if (v[nx] == -1) v[nx] = v[x];
			ans[nx] = max(ans[nx], ans[x] + (nx >= p + 1 and nx <= p + q ? 1 : 0));
			if (--sz[nx]) continue;
			if (nx > p + q) v[nx] = v[x];
			else {
				if (a[nx] == 1) v[nx] = (v[nx] and v[x]);
				if (a[nx] == 2) v[nx] = (v[nx] or v[x]);
				if (a[nx] == 3) v[nx] = (v[nx] xor v[x]);
				if (a[nx] == 4) v[nx] = !v[nx];
			}
			qu.push(nx);
		}
	}
	int k = 0;
	for (int i = p + q + 1;i <= p + q + r;i++) k = max(k, ans[i]);
	cout << k << '\n';
	for (int i = p + q + 1;i <= p + q + r;i++) cout << v[i] << ' ';
}
