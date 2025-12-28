#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> cnt(200001), dp(200001);
		for (int i = 0;i < n;i++) {
			int x;
			cin >> x;
			cnt[x]++;
		}
		for (int i = 1;i <= 200000;i++) {
			dp[i] += cnt[i];
			for (int j = 2;j * i <= 200000;j++) dp[i * j] = max(dp[i * j], dp[i]);
		}
		cout << n - *max_element(dp.begin(), dp.end()) << '\n';
	}
}
