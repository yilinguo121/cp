#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		unordered_map<int, int> cnt;
		for (int i = 0;i < n;i++) {
			int x;
			cin >> x;
			cnt[x]++;
		}
		vector<int> num(n + 2);
		for (auto [a, b] : cnt) num[b]++;
		int ans = 0;
		for (int i = n;i >= 1;i--) {
			num[i] += num[i + 1];
			ans = max(ans, num[i] * i);
		}
		cout << ans << '\n';
	}
}
