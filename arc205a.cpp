#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, q;
	cin >> n >> q;
	vector<string> s(n);
	for (auto &x : s) cin >> x;
	vector<vector<int>> v(n + 1, vector<int>(n + 1));
	for (int i = 1;i < n;i++) {
		for (int j = 1;j < n;j++) {
			v[i][j] = (s[i - 1][j - 1] == '.' and s[i - 1][j] == '.' and s[i][j - 1] == '.' and s[i][j] == '.') + v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
		}
	}
	while (q--) {
		int x1, x2, y1, y2;
		cin >> x1 >> x2 >> y1 >> y2;
		x2--;
		y2--;
		cout << v[x2][y2] - v[x1 - 1][y2] - v[x2][y1 - 1] + v[x1 - 1][y1 - 1] << '\n';
	}
}

