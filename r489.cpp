#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<vector<int>> f(vector<vector<int>> a) {
	int n = a.size(), m = a[0].size();
	vector<vector<int>> t(m, vector<int>(n));
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			t[i][j] = a[n - 1 - j][i];
		}
	}
	return t;
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> b[i][j];
		}
	}
	int s = 0;
	for (int k = 0;k < 4;k++) {
		if (a.size() == b.size() and a[0].size() == b[0].size()) {
			int now = 0;
			for (int i = 0;i < n;i++) {
				for (int j = 0;j < m;j++) {
					if (a[i][j] == b[i][j]) now++;
				}
			}
			s = max(s, now);
		}
		a = f(a);
	}
	cout << (100 * s) / (n * m) << '%';
}
