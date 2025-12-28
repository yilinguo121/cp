#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<int> pre, in, pos;
vector<pair<int, int>> ans;
void dfs(int l1, int r1, int l2, int r2) {
	if (l1 > r1) return;
	int root = pre[l1];
	int mid = pos[root];
	if (mid < l2 or mid > r2) {
		cout << -1;
		exit(0);
	}
	if (l2 < mid) {
		ans[root - 1].first = pre[l1 + 1];
		dfs(l1 + 1, l1 + mid - l2, l2, mid - 1);
	}
	if (r2 > mid) {
		ans[root - 1].second = pre[l1 + mid - l2 + 1];
		dfs(l1 + mid - l2 + 1, r1, mid + 1, r2);
	}
}
int main() {
	int n;
	cin >> n;
	pre.resize(n);
	in.resize(n);
	pos.resize(n + 1);
	ans.resize(n);
	for (auto &x : pre) cin >> x;
	for (int i = 0;i < n;i++) {
		cin >> in[i];
		pos[in[i]] = i;
	}
	if (pre[0] != 1) {
		cout << -1;
		return 0;
	}
	dfs(0, n - 1, 0, n - 1);
	for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
}

