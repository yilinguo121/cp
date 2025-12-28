#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<vector<int>> v(n + 1);
		vector<int> ans(n);
		for (int i = 0;i < n;i++) {
			int x;
			cin >> x;
			if (v[x].size() < k) v[x].push_back(i);
		}
		int m = 0;
		for (auto x : v) m += x.size();
		int pos = 0, now = 0;
		for (int i = 0;i < m / k * k;i++) {
			while (now == v[pos].size()) pos++, now = 0;
			ans[v[pos][now]] = (i % k) + 1;
			now++;
		}
		for (auto x : ans) cout << x << ' ';
		cout << '\n';
	}
}
