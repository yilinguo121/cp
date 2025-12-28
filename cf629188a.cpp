#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<int> v;
vector<int> ans;
int n, t;
vector<string> s;
void dfs(int id) {
	if (id == n) {
		int now = 0;
		for (auto x : ans) now ^= x;
		if (now == t) {
			string x;
			for (int i = 0;i < n;i++) x += to_string(ans[i]) + (i < n - 1 ? '^' : '=');
			s.push_back(x);
		}
		return;
	}
	for (int i = 0;i <= v[id];i++) {
		ans.push_back(i);
		dfs(id + 1);
		ans.pop_back();
	}
}
int main() {
	IO
	cin >> n >> t;
	v.resize(n);
	for (auto &x : v) cin >> x;
	dfs(0);
	cout << s.size() << '\n';
	for (auto x : s) cout << x << t << '\n';
}

