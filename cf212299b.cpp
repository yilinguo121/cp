#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
const int t = 3000000;
int mp[6000000];
vector<int> v;
int n, cnt, ans = INF;
void dfs(int id, int now) {
	if (cnt > ans) return;
	if (id == n) {
		ans = min(ans, cnt);
		return;
	}
	if (!mp[now + v[id] + t]) cnt++;
	mp[now + v[id] + t]++;
	dfs(id + 1, now + v[id]);
	mp[now + v[id] + t]--;
	if (!mp[now + v[id] + t]) cnt--;

	if (!mp[now - v[id] + t]) cnt++;
	mp[now - v[id] + t]++;
	dfs(id + 1, now - v[id]);
	mp[now - v[id] + t]--;
	if (!mp[now - v[id] + t]) cnt--;
}
int main() {
	IO
	cin >> n;
	v.resize(n);
	for (auto &x : v) cin >> x;
	mp[0 + t]++;
	cnt++;
	dfs(0, 0);
	cout << ans;
}

