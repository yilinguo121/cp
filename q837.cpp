#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int m, n, k;
	cin >> m >> n >> k;
	vector<string> s(m);
	for (auto &x : s) cin >> x;
	vector<int> pos(m, 0);
	int ans = 0;
	while (k--) {
		for (int i = 0;i < m;i++) {
			int x;
			cin >> x;
			pos[i] -= x;
		}
		for (int i = 0;i < n;i++) {
			int a[26] = {}, MAX = 0;
			for (int j = 0;j < m;j++) {
				MAX = max(MAX, ++a[s[j][(((i + pos[j]) % n) + n) % n] - 'a']);
			}
			ans += MAX;
		}
	}
	cout << ans;
}

