#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int line(vector<int> &v) {
	int now = 0, best = -INF;
	for (auto x : v) {
		now += x;
		best = max(best, now);
		now = max(0, now);
	}
	return best;
}
int cycle(vector<int> &v) {
	int sum = 0, mx_now = 0, mx_best = -INF, mn_now = 0, mn_best = INF;
	for (auto x : v) {
		sum += x, mx_now += x, mn_now += x;
		mx_best = max(mx_best, mx_now);
		mx_now = max(0, mx_now);
		mn_best = min(mn_best, mn_now);
		mn_now = min(0, mn_now);
	}
	if (mx_best < 0) return mx_best;
	return max(mx_best, sum - mn_best);
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> to(n + 1, -1), w(n + 1, -INF), in(n + 1);
	for (int i = 0;i < m;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		to[a] = b;
		w[a] = c;
		in[b]++;
	}
	vector<bool> vis(n + 1);
	int ans = *max_element(w.begin(), w.end());
	for (int i = 1;i <= n;i++) {
		if (to[i] != -1 and !in[i]) {
			vector<int> v;
			int t = i;
			while (to[t] != -1) {
				vis[t] = 1;
				v.push_back(w[t]);
				t = to[t];
			}
			ans = max(ans, line(v));
		}
	}
	for (int i = 1;i <= n;i++) {
		if (to[i] != -1 && !vis[i]) {
			vector<int> v;
			int t = i;
			while (!vis[t]) {
				vis[t] = 1;
				v.push_back(w[t]);
				t = to[t];
			}
			ans = max(ans, cycle(v));
		}
	}
	cout << ans;
}
