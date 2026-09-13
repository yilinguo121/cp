#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(m);
	for (auto &x : v) cin >> x;
	vector<vector<int>> st(m, vector<int>(20));
	for (int i = 0;i < m;i++) st[i][0] = v[i];
	for (int j = 1;j < 20;j++) for (int i = 0;i + (1 << j) - 1 < m;i++) st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	int q;
	cin >> q;
	while (q--) {
		int x1, y1, x2, y2, k;
		bool ans = 0;
		cin >> x1 >> y1 >> x2 >> y2 >> k;
		x1--, y1--, x2--, y2--;
		if (y1 > y2) swap(x1, x2), swap(y1, y2);
		if (abs(x1 - x2) % k == 0 and abs(y1 - y2) % k == 0) {
			ans = 1;
			int lg = log2(y2 - y1 + 1), h = max(st[y1][lg], st[y2 - (1 << lg) + 1][lg]);
			if (h > x1 and x1 + ((h - x1 + k - 1) / k) * k >= n) ans = 0;
		}
		cout << (ans ? "YES\n" : "NO\n");
	}
}

