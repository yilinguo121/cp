#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	while (cin >> n) {
		vector<int> v(n);
		for (auto &x : v) cin >> x;
		vector<int> ans(n + 1);
		for (int i = 0;i < n;i++) {
			for (int j = i;j < n;j++) {
				int cnt = 0;
				for (int k = i;k <= j;k++) {
					cnt += (v[k] >= min(v[i], v[j]));
				}
				ans[cnt]++;
			}
		}
		for (int i = 1;i <= n;i++) cout << ans[i] << '\n';
	}
}
