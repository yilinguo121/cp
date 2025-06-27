#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans = 0;;
		queue<tuple<int, int, int>> q;
		q.push({0, 0, 0});
		while (!q.empty()) {
			auto [x, t, m] = q.front();
			q.pop();
			ans = max(ans, m);
			if (x >= n) continue;
			if (s[x] == '0') {
				if (t) q.push({x + 1, t - 1, m + 1});
				else q.push({x + 1, t, m});
			}
			if (s[x] == '1') {
				if (t) q.push({x + 1, t - 1, m + 1});
				q.push({x + 1, t + 1, m});
			}
			if (s[x] == '2') {
				q.push({x + 1, t, m + 1});
			}
			if (s[x] == '3') {
				q.push({x + 1, t, m + 1});
				q.push({x + 1, t + 1, m});
			}
		}
		cout << ans << '\n';
	}
}

