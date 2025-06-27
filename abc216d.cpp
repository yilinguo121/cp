#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1);
	vector<int> sz(n + 1);
	while (m--) {
		int k;
		cin >> k;
		int prev = 0;
		while (k--) {
			int x;
			cin >> x;
			v[prev].push_back(x);
			sz[x]++;
			prev = x;
		}
	}
	queue<int> q;
	q.push(0);
	int cnt = 0; // 0~n都可以就yes
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		cnt++;
		for (auto nt : v[t]) {
			sz[nt]--;
			if (!sz[nt]) q.push(nt);
		}
	}
	cout << (cnt == n + 1 ? "Yes" : "No");
}

