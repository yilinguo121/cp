#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	vector<bool> dp(k + 1);
	for (auto &x : v) cin >> x;
	for (int i = 1;i <= k;i++) {
		for (auto x : v) {
			if (i < x) break;
			if (!dp[i - x]) {
				dp[i] = 1;
				break;
			}
		}
	}
	cout << (dp[k] ? "First" : "Second");
}
