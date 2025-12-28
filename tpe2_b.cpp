#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max() / 2;
signed main() {
	IO
	int n, m, k;
	while (cin >> n >> m >> k) {
		vector<vector<pair<int, int>>> v(n);
		while (m--) {
			int a, b, w;
			cin >> a >> b >> w;
			a--, b--;
			bool flag = 1;
			for (int i = 0;i < v[a].size();i++) if (v[a][i].first == b) {
				v[a][i] = min(v[a][i], {b, w});
				flag = 0;
				break;
			}
			if (flag) v[a].push_back({b, w});
		}
		vector<pair<int, int>> p(n, {-1, -1});
		vector<int> a(n, INF);
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < v[i].size();j++) {
				int old = v[i][j].second;
				if (k) v[i][j].second /= 2;
				//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
				queue<pair<int, int>> q;
				vector<int> ans(n, INF);
				q.push({0, 0});
				while (!q.empty()) {
					auto [dis, t] = q.front();
					q.pop();
					for (auto [nt, w] : v[t]) {
						if (ans[nt] >= dis + w) {
							q.push({dis + w, nt});
							ans[nt] = dis + w;
							p[nt] = {t, w};
							a[nt] = min(a[nt], ans[nt]);
						}
					}
				}
				v[i][j].second = old;
			}
		}
		for (int i = 1;i < n;i++) {
			cout << (a[i] == INF ? -1 : a[i]) << '\n';
		}
		/*
		for (int i = 1;i < n;i++) {
			if (ans[i] == INF) {
				cout << "-1\n";
				continue;
			}
			int x = i;
			priority_queue<float, vector<float>, greater<float>> pq;
			while (x != -1) {
				pq.push(p[x].second);
				x = p[x].first;
			}
			int have = k;
			while (have--) {
				pq.push(pq.top() / 2);
				pq.pop();
			}
			int ans = 0;
			while (!pq.empty()) {
				ans += (int)pq.top();
				pq.pop();
			}
			cout << ans << '\n';
		}
		*/
	}
}
