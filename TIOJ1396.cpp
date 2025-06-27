#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int start, finish;
int f(vector<pair<int, int>> v, int n) {
	if (start == finish) {
		for (auto [x, y] : v) {
			if (x <= start and finish <= y) return 1;
		}
		return INF;
	}
	int now = start, l = 0, cnt = 0;
	sort(v.begin(), v.end());
	while (now < finish) {
		int t = now;
		while (l < n and v[l].first <= now) {
			t = max(t, v[l].second);
			l++;
		}
		if (t <= now) return INF;
		now = t;
		cnt++;
	}
	return cnt;
}
int main() {
	IO
	int n, m;
	while (cin >> n >> m) {
		vector<pair<int, int>> a(n), b(m);
		for (auto &[x, y] : a) cin >> x >> y;
		for (auto &[x, y] : b) cin >> x >> y;
		cin >> start >> finish;
		int need_a = f(a, n);
		int need_b = f(b, m);
		if (need_a == INF and need_b == INF) cout << "TIE\n";
		else if (need_b == INF or need_a <= need_b) cout << "A WIN\n";
		else cout << "B WIN\n";
	}
}
