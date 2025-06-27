#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> v(n + 1);
	for (int i = 1;i < n;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bitset<200001> mp;
	while (k--) {
		int x;
		cin >> x;
		mp[x] = 1;
	}
	queue<int> q;
	vector<int> sz(n + 1);
	for (int i = 1;i <= n;i++) {
		sz[i] = v[i].size();
		if (v[i].size() == 1 and !mp[i]) q.push(i);
	}
	int ans = n;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		ans--;
		for (auto nt : v[t]) {
			sz[nt]--;
			if (sz[nt] == 1 and !mp[nt]) {
				q.push(nt);
			}
		}
	}
	cout << ans;
}
