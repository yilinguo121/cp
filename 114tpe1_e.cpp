#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	vector<vector<int>> v(n);
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a - 1].push_back(b - 1);
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (i != j and (a[i] & a[j]) == a[j]) {
				v[i].push_back(j);
			}
		}
	}
	vector<int> ans(n, -1);
	ans[0] = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		for (auto nt : v[t]) {
			if (ans[nt] != -1) continue;
			ans[nt] = ans[t] + 1;
			q.push(nt);
		}
	}
	for (auto x : ans) cout << x << '\n';
}

