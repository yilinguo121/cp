#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int n, m;
bitset<101> vis;
vector<int> f() {
	string s;
	cin >> s;
	if (s == "OK" or s == "-1") exit(0);
	vector<int> v(stoi(s));
	for (auto &x : v) cin >> x;
	return v;
}
void dfs(int t) {
	vis[t] = 1;
	auto v = f();
	for (auto nt : v) {
		if (vis[nt]) continue;
		cout << nt << '\n';
		cout.flush();
		dfs(nt);
		cout << t << '\n';
		f();
	}
}
int main() {
	cin >> n >> m;
	dfs(1);
}

