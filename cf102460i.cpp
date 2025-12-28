#include <bits/stdc++.h>
using namespace std;
int cnt[1000] = {};
bool vis[1000] = {};
int n;
vector<int>  now;
set<vector<int>> ans;
priority_queue<int> q;
int find() {
	while (!q.empty() and cnt[q.top()] == 0) vis[q.top()] = 0, q.pop();
	return q.empty() ? -1 : q.top();
}
bool check(int l, int r, int x) {
	bool flag = 1;
	for (int i = 0;i < l;i++) {
		if (--cnt[abs(now[i] - x)] < 0) flag = 0;
	}
	for (int i = n - 1;i > r;i--) {
		if (--cnt[abs(now[i] - x)] < 0) flag = 0;
	}
	return flag;
}
void back(int l, int r, int x) {
	for (int i = 0;i < l;i++) {
		if (!cnt[abs(now[i] - x)] and !vis[abs(now[i] - x)]) q.push(abs(now[i] - x)), vis[abs(now[i] - x)] = 1;
		cnt[abs(now[i] - x)]++;
	}
	for (int i = n - 1;i > r;i--) {
		if (!cnt[abs(now[i] - x)] and !vis[abs(now[i] - x)]) q.push(abs(now[i] - x)), vis[abs(now[i] - x)] = 1;
		cnt[abs(now[i] - x)]++;
	}
}
void dfs(int l, int r) {
	if (l > r) {
		ans.insert(now);
		return;
	}
	int big = find();
	now[l] = now[n - 1] - big;
	if (check(l, r, now[l])) dfs(l + 1, r);
	back(l, r, now[l]);
	now[r] = big;
	if (check(l, r, now[r])) dfs(l, r - 1);
	back(l, r, now[r]);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	if (n == 1) {
		cout << 0 << '\n' << 0 << '\n';
		return 0;
	}
	for (int i = 0;i < n * (n - 1) / 2;i++) {
		int x;
		cin >> x;
		if (!cnt[x] and !vis[x]) q.push(x), vis[x] = 1;
		cnt[x]++;
	}
	now.assign(n, 0);
	now[n - 1] = find();
	cnt[now[n - 1]]--;
	dfs(1, n - 2);
	cout << ans.size() << '\n';
	for (auto x : ans) {
		for (auto t : x) cout << t << ' ';
		cout << '\n';
	}
}
