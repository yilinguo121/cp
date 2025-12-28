#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<int> cnt(n);
	int sum = 0;
	for (auto &x : cnt) {
		cin >> x;
		if (x < 0 or x > n - 1) {
			cout << "IMPOSSIBLE";
			return 0;
		}
		sum += x;
	}
	if (sum % 2) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	priority_queue<pair<int, int>> q;
	for (int i = 0;i < n;i++) q.push({cnt[i], i});
	vector<pair<int, int>> ans;
	while (!q.empty()) {
		auto [w, t] = q.top();
		q.pop();
		if (q.size() < w) {
			cout << "IMPOSSIBLE";
			return 0;
		}
		vector<pair<int, int>> get;
		for (int i = 0;i < w;i++) {
			auto [nw, nt] = q.top();
			q.pop();
			ans.push_back({t, nt});
			get.push_back({nw - 1, nt});
		}
		for (auto [nw, nt] : get) if (nw) q.push({nw, nt});
	}
	cout << ans.size() << '\n';
	for (auto [a, b] : ans) cout << a + 1 << ' ' << b + 1 << '\n';
}

