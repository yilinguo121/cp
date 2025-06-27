#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> v(n + 1);
		vector<int> a(m), b(m), sz(n + 1), pos(n + 1);
		for (int i = 0;i < m;i++) {
			int type;
			cin >> type >> a[i] >> b[i];
			if (type) {
				v[a[i]].push_back(b[i]);
				sz[b[i]]++;
			}
		}
		queue<int> q;
		for (int i = 1;i <= n;i++) if (!sz[i]) q.push(i);
		int now = 0;
		while (!q.empty()) {
			auto t = q.front();
			q.pop();
			now++;
			pos[t] = now;
			for (auto nt : v[t]) if (!--sz[nt]) q.push(nt);
		}
		if (now != n) cout << "NO\n";
		else {
			cout << "YES\n";
			for (int i = 0;i < m;i++) {
				if (pos[a[i]] > pos[b[i]]) cout << b[i] << ' ' << a[i] << '\n';
				else cout << a[i] << ' ' << b[i] << '\n';
			}
		}
	}
}

