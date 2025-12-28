#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
vector<vector<int>> v;
signed main() {
	IO
	int n;
	cin >> n;
	v.resize(n);
	vector<int> cnt(n, 1), p(n);
	for (int i = 1;i < n;i++) {
		cin >> p[i];
		v[p[i]].push_back(i);
	}
	for (int i = n - 1;i > 0;i--) cnt[p[i]] += cnt[i];
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	vector<int> pos(n);
	q.push({cnt[0], 0});
	int ans = 0;
	int now = 1;
	while (!q.empty()) {
		auto [w, t] = q.top();
		pos[t] = now++;
		ans += pos[t] - pos[p[t]];
		q.pop();
		cout << t << ' ';
		for (auto nt : v[t]) {
			q.push({cnt[nt], nt});
		}
	}
	cout << '\n' << ans;
}
