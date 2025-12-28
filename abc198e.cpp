#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<int> color;
vector<vector<int>> v;
bitset<100001> vis;
vector<int> cnt(100001);
vector<bool> ans;
void dfs(int t) {
	vis[t] = 1;
	ans[t] = !cnt[color[t]];
	cnt[color[t]]++;
	for (auto nt : v[t]) if (!vis[nt]) dfs(nt);
	cnt[color[t]]--;
}
int main() {
	int n;
	cin >> n;
	color.resize(n + 1);
	v.resize(n + 1);
	for (int i = 1;i <= n;i++) cin >> color[i];
	for (int i = 0;i < n - 1;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	ans.resize(n + 1);
	dfs(1);
	for (int i = 1;i <= n;i++) if (ans[i]) cout << i << '\n';
}
