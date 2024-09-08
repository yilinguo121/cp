#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, p, l, r;
	cin >> n >> p >> l >> r;
	vector<int> s(n);
	bool vis[n] = {};
	for (int i = 0;i < n;i++) {
		cin >> s[i];
	}
	queue<int> q;
	q.push(s[0]);
	vis[s[0]] = 1;
	int dis[n] = {};
	dis[s[0]] = 0;
	while (q.size()) {
		int t = q.front();
		q.pop();
		for (int i : {t - l, t + r}) {
			if (i < 0 or i >= n) continue;
			if (s[i] < 0 or s[i] >= n) continue;
			if (vis[s[i]]) continue;
			if (i == t) continue;
			q.push(s[i]);
			vis[s[i]] = 1;
			dis[s[i]] = dis[t] + 1;
		}
	}
	if (p < 0 or 0 >= n or !vis[p]) cout << -1;
	else cout << dis[p];
}
