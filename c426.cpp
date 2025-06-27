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
		vector<vector<int>> v(n);
		vector<int> cnt(n);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		while (m--) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
			if (a < b) cnt[a]++;
			else cnt[b]++;
		}
		int MAX = 0;
		for (int i = 0;i < n;i++) {
			MAX = max(MAX, cnt[i]);
			cnt[i] = v[i].size();
			q.push({cnt[i], i});
		}
		cout << MAX << ' ';
		MAX = 0;
		while (!q.empty()) {
			auto [t, x] = q.top();
			q.pop();
			if (cnt[x] == -1) continue;
			MAX = max(MAX, t);
			cnt[x] = -1;
			for (auto nx : v[x]) {
				if (cnt[nx] == -1) continue;
				cnt[nx]--;
				q.push({cnt[nx], nx});
			}
		}
		cout << MAX << '\n';
	}
}
