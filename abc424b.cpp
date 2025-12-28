#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	bool v[n + 1][m + 1] = {};
	while (k--) {
		int a, b;
		cin >> a >> b;
		v[a][b] = 1;
		bool flag = 1;
		for (int i = 1;i <= m;i++) {
			if (!v[a][i]) {
				flag = 0;
				break;
			}
		}
		if (flag) cout << a << ' ';
	}
}

