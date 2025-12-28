#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	int ans = 0;
	while (1) {
		int j = -1, now = INF;
		for (int i = 0;i < n;i++) {
			if (v[i]) {
				j = i;
				break;
			}
		}
		if (j == -1) break;
		int k = n;
		for (int i = 0;i < n;i++) {
			if (!v[(j + i) % n]) {
				k = i;
				break;
			}
			now = min(now, v[(j + i) % n]);
		}
		ans += now;
		for (int i = 0;i < k;i++) v[(j + i) % n] -= now;
	}
	cout << ans;
}

