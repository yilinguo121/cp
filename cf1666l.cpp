#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int n, m, s;
vector<vector<int>> v;
vector<int> p, first;
vector<int> f(int x) {
	vector<int> now;
	while (x != s) {
		now.push_back(x);
		x = p[x];
	}
	now.push_back(x);
	reverse(now.begin(), now.end());
	return now;
}
void ans(int x, int y) {
	auto ans1 = f(x), ans2 = f(y);
	ans1.push_back(y);
	cout << "Possible\n";
	cout << ans1.size() << '\n';
	for (auto t : ans1) cout << t << ' ';
	cout << '\n' << ans2.size() << '\n';
	for (auto t : ans2) cout << t << ' ';
	exit(0);
}
void dfs(int t, int pa) {
	first[t] = pa;
	for (auto nt : v[t]) {
		if (!first[nt]) {
			p[nt] = t;
			dfs(nt, pa);
		}
		else if (first[nt] != pa) {
			ans(t, nt);
		}
	}
}
int main() {
	IO
	cin >> n >> m >> s;
	v.resize(n + 1);
	p.resize(n + 1);
	first.resize(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		if (b == s) continue;
		v[a].push_back(b);
	}
	for (auto nt : v[s]) {
		if (first[nt] and first[nt] != nt) {
			ans(s, nt);
		}
		if (first[nt]) continue;
		p[nt] = s;
		dfs(nt, nt);
	}
	cout << "Impossible";
}

