#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n, m;
	cin >> n >> m;
	int sz = sqrt(n);
	vector<int> v(n), nxt(n), cnt(n), last(n);
	for (auto &x : v) cin >> x;
	for (int i = n - 1, j, r;i >= 0;i--) {
		j = i + v[i];
		r = min(n - 1, i / sz * sz + sz - 1);
		if (j > r) nxt[i] = j, cnt[i] = 1, last[i] = i;
		else nxt[i] = nxt[j], cnt[i] = cnt[j] + 1, last[i] = last[j];
	}
	while (m--) {
		int type, x, y;
		cin >> type >> x;
		if (type == 0) {
			cin >> y;
			v[--x] = y;
			for (int l = x / sz * sz, r = min(n, l + sz) - 1, i = r;i >= l;i--) {
				int j = i + v[i];
				if (j > r) nxt[i] = j, cnt[i] = 1, last[i] = i;
				else nxt[i] = nxt[j], cnt[i] = cnt[j] + 1, last[i] = last[j];
			}
		}
		else {
			int now = --x, ans = 0, fin = -1;
			while (now < n) fin = last[now], ans += cnt[now], now = nxt[now];
			cout << fin + 1 << ' ' << ans << '\n';
		}
	}
}
