#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int all = 0;
	vector<int> w, m;
	for (int i = 0;i < n;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = 0;j < c;j++) {
			w.push_back(a);
			m.push_back(b);
		}
		all += c;
	}
	int t;
	cin >> t;
	int dp[2][t + 1] = {};
	for (int i = 1;i <= all;i++) {
		for (int j = 0;j <= t;j++) {
			dp[i % 2][j] = dp[(i - 1) % 2][j];
			if (j >= w[i - 1]) {
				dp[i % 2][j] = max(dp[i % 2][j], dp[(i - 1) % 2][j - w[i - 1]] + m[i - 1]);
			}
		}
	}
	cout << dp[all % 2][t];
}
