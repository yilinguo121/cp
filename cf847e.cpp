#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<int> p, s;
bool f(int t) {
	int pos = 0;
	for (int i = 0;i < p.size() and pos < s.size();i++) {
		if (s[pos] < p[i]) {
			if (p[i] - s[pos] > t) return 0;
			int r = max(t - p[i] + 2 * s[pos], (t + p[i] + s[pos]) / 2);
			// 往左再往右 (p - s) + (r - s) <= t -> p - 2s + r <= t -> r <= t - p + 2s
			// 往右再往左 (r - p) + (r - s) <= t -> 2r - p - s <= t -> r <= (t + p + s) / 2
			while (pos < s.size() and s[pos] <= r) pos++;
		}
		else {
			int r = p[i] + t;
			while (pos < s.size() and s[pos] <= r) pos++;
		}
	}
	return pos == s.size();
}
int main() {
	IO
	int n;
	string x;
	cin >> n >> x;
	for (int i = 0;i < n;i++) {
		if (x[i] == '*') s.push_back(i);
		if (x[i] == 'P') p.push_back(i);
	}
	int l = 0, r = 2 * n, ans = 0;
	while (l <= r) {
		int m = (l + r) / 2;
		if (f(m)) {
			r = m - 1;
			ans = m;
		}
		else l = m + 1;
	}
	cout << ans;
}
