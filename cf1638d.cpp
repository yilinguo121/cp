#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int s[1000][1000];
int n, m, t;
vector<tuple<int, int, int>> ans;
bool check(int x, int y) {
	if (s[x][y] == -1 and s[x + 1][y] == -1 and s[x][y + 1] == -1 and s[x + 1][y + 1] == -1) return 0;
	t = -1;
	for (int i = 0;i < 2;i++) {
		for (int j = 0;j < 2;j++) {
			if (s[x + i][y + j] != -1) {
				if (t == -1) t = s[x + i][y + j];
				else if (t != s[x + i][y + j]) return 0;
			}
		}
	}
	return 1;
}
void f(int x, int y) {
	ans.push_back({x + 1, y + 1, t});
	s[x][y] = -1;
	s[x + 1][y] = -1;
	s[x][y + 1] = -1;
	s[x + 1][y + 1] = -1;
	for (int i = max(0, x - 1);i <= min(n - 2, x + 1);i++) {
		for (int j = max(0, y - 1);j <= min(m - 2, y + 1);j++) {
			if (check(i, j)) f(i, j);
		}
	}
}
int main() {
	IO
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> s[i][j];
		}
	}
	for (int i = 0;i < n - 1;i++) {
		for (int j = 0;j < m - 1;j++) {
			if (check(i, j)) f(i, j);
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (s[i][j] != -1) {
				cout << -1;
				return 0;
			}
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto [a, b, c] : ans) cout << a << ' ' << b << ' ' << c << '\n';
}

