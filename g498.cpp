#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m, d;
	cin >> n >> m >> d;
	int dp[d + 1] = {};
	dp[0] = 1;
	for (int i = 0;i <= d;i++) {
		if (i >= n and dp[i - n]) {
			dp[i]++;
		}
		if (i >= m and dp[i - m]) {
			dp[i]++;
		}
	}
	if (dp[d] >= 1) {
		cout << "YES";
		return 0;
	}
	cout << "NO";
}
