#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int n, m = 0;
		cin >> n;
		vector<vector<int>> v(n);
		for (auto &x : v) {
			int k;
			cin >> k;
			m = max(k, m);
			x.resize(k);
			for (auto &y : x) cin >> y;
		}
		sort(v.begin(), v.end());
		vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> q(m);
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < v[i].size();j++) q[j].push({v[i][j], i});
		}
		vector<bool> vis(n);
		for (int i = 0;i < m;i++) {
			while (vis[q[i].top().second]) q[i].pop();
			int now = q[i].top().second;
			q[i].pop();
			vis[now] = 1;
			for (int j = i;j < v[now].size();j++) cout << v[now][j] << ' ';
			i = v[now].size() - 1;
		}
		cout << '\n';
	}
}
