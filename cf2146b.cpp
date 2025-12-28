#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> v(n);
		vector<int> cnt(m + 1);
		for (auto &x : v) {
			int k;
			cin >> k;
			x.resize(k);
			for (auto &y : x) {
				cin >> y;
				cnt[y]++;
			}
		}
		bool flag = 0;
		for (int i = 1;i <= m;i++) {
			if (!cnt[i]) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			cout << "No\n";
			continue;
		}
		vector<bool> need(n);
		int num = 0;
		for (int i = 0;i < n;i++) {
			for (auto x : v[i]) {
				if (cnt[x] == 1) {
					need[i] = 1;
					num++;
					break;
				}
			}
		}
		cout << (n - num >= 2 ? "Yes\n" : "No\n");
	}
}

