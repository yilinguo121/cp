#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<int> pre, in, pos;
void dfs(int l1, int r1, int l2) {
	if (l1 > r1) return;
	if (l1 == r1) {
		cout << pre[l1] << ' ';
		return;
	}
	dfs(l1 + 1, l1 + pos[pre[l1]] - l2, l2);
	dfs(l1 + pos[pre[l1]] - l2 + 1, r1, pos[pre[l1]] + 1);
	cout << pre[l1] << ' ';
}
int main() {
	IO
	int n;
	cin >> n;
	pre.resize(n);
	in.resize(n);
	pos.resize(n + 1);
	for (auto &x : pre) cin >> x;
	for (int i = 0;i < n;i++) {
		cin >> in[i];
		pos[in[i]] = i;
	}
	dfs(0, n - 1, 0);
}

