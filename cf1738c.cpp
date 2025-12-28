#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int dp[105][105][2][2];
bool dfs(int odd, int even, bool turn, bool win) {
	if(!odd and !even) return !win;
	int &now = dp[odd][even][turn][win];
	if (now != -1) return now;
	if (turn == 0) {
		now = 0;
		if (even and dfs(odd, even - 1, 1, win)) now = 1;
		if (odd and dfs(odd - 1, even, 1, !win)) now = 1;
	}
	else {
		now = 1;
		if (even and !dfs(odd, even - 1, 0, win)) now = 0;
		if (odd and !dfs(odd - 1, even, 0, win)) now = 0;
	}
	return now;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int odd = 0, even = 0;
		while (n--) {
			int x;
			cin >> x;
			if (x % 2) odd++;
			else even++;
		}
		memset(dp, -1, sizeof(dp));
		cout << (dfs(odd, even, 0, 0) ? "Alice\n" : "Bob\n");
	}
}

