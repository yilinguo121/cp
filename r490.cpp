#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	map<string, int> cnt;
	int ans = 0;
	while (n--) {
		string x;
		cin >> x;
		int s1 = 0, s2 = 0;
		for (int i = 0;i < 12;i++) {
			if ((i + 1) % 2) s1 += x[i] - '0';
			else s2 += x[i] - '0';
		}
		int k = (s1 + 3 * s2) % 10 + (x[12] - '0');
		if (k == 0 or k == 10) {
			cnt[x.substr(0, 3)]++;
			ans = max(ans, cnt[x.substr(0, 3)]);
		}
	}
	for (auto [x, y] : cnt) {
		if (y == ans) {
			cout << x << ' ' << ans;
			return 0;
		}
	}
}

