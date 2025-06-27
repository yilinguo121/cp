#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<vector<pair<int, int>>> p(200005);
int n;
bool f(int m) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	for (int now = 1;now <= n;now++) {
		for (auto x : p[now]) q.push(x);
		int can = m;
		while (can > 0 and !q.empty()) {
			auto [r, cnt] = q.top();
			q.pop();
			if (r < now) return 0;
			int take = min(cnt, can);
			cnt -= take;
			can -= take;
			if (cnt) {
				if (r == now) return 0;
				q.push({r, cnt});
			}
		}
	}
	return 1;
}
int main() {
	IO
	cin >> n;
	vector<int> a(n + 5), b(n + 5);
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) cin >> b[i];
	for (int i = 1;i <= n;i++) p[max(1, i - b[i])].push_back({min(n, i + b[i]), a[i]});
	int l = 0, r = 1e9;
	while (l <= r) {
		int m = (l + r) / 2;
		if (f(m)) r = m - 1;
		else l = m + 1;
	}
	cout << r + 1;
}
