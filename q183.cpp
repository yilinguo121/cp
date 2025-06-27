#include <bits/stdc++.h>
using namespace std;
int cnt[101] = {};
int n;
vector<int> ma, mi, now;
int find() {
	for (int i = 100;i >= 0;i--) {
		if (cnt[i]) return i;
	}
	return -1;
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
		cnt[abs(now[i] - x)]++;
	}
	for (int i = n - 1;i > r;i--) {
		cnt[abs(now[i] - x)]++;
	}
}
void dfs(int l, int r) {
	if (l > r) {
		mi = min(mi, now);
		ma = max(ma, now);
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
		cnt[x]++;
	}
	ma.assign(n, 0);
	mi.assign(n, 100);
	now.assign(n, 0);
	now[n - 1] = find();
	cnt[now[n - 1]]--;
	dfs(1, n - 2);
	for (int i = 0;i < n;i++) cout << mi[i] << ' ';
	cout << '\n';
	for (int i = 0;i < n;i++) cout << ma[i] << ' ';
}

