#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<vector<int>> v;
vector<int> pa;
vector<bool> vis1, vis2;
vector<pair<int, int>> all;
int a, b;
bool flag = 0, mode = 1;
void dfs(int t) {
	if (flag) return;
	vis1[t] = vis2[t] = 1;
	for (auto nt : v[t]) {
		if (t == a and nt == b) continue;
		if (vis2[nt]) {
			flag = 1;
			if (mode) {
				all.push_back({t, nt});
				while (t != nt) {
					all.push_back({pa[t], t});
					t = pa[t];
				}
			}
			return;
		}
		if (vis1[nt]) continue;
		pa[nt] = t;
		dfs(nt);
		if (flag) return;
	}
	vis2[t] = 0;
}
int main() {
	IO
	int n, m;
	cin >> n >> m;
	v.resize(n + 1);
	pa.resize(n + 1);
	while (m--) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
	}
	vis1.assign(n + 1, 0);
	vis2.assign(n + 1, 0);
	a = b = 0;
	for (int i = 1;i <= n;i++) {
		if (!vis1[i]) dfs(i);
		if (flag) break;
	}
	if (!flag) {
		cout << "YES";
		return 0;
	}
	all = vector<pair<int,int>>(all.begin(), all.end());
	mode = 0;
	for (auto [x, y] : all) {
		a = x;
		b = y;
		vis1.assign(n + 1, 0);
		vis2.assign(n + 1, 0);
		flag = 0;
		for (int i = 1;i <= n;i++) {
			if (!vis1[i]) dfs(i);
			if (flag) break;
		}
		if (!flag) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}
