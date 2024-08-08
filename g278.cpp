#include<bits/stdc++.h>
using namespace std;
int dp[22][1000005], l[1000005];
int main() {
	int n, k;
	cin >> n >> k;
	deque<int> d;
	vector<bool> v(100005);
	vector<int> f(n);
	for (int i = 0;i < n;i++) {
		cin >> f[i];
	}
	for (int i = n - 1;i >= 0;i--) {
		while(v[f[i]]) {
			v[d.front()] = 0;
			d.pop_front();
		}
		d.push_back(f[i]);
		v[f[i]] = 1;
		l[i] = d.size();
		dp[1][i + l[i] - 1] = max(dp[1][i + l[i] - 1], l[i]);
	}
	for (int i = 1;i <= k;i++) {
		dp[i][i - 1] = i;
		for (int j = i;j < n;j++) {
			dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			dp[i + 1][j + l[j] - 1] = max(dp[i + 1][j + l[j] - 1], dp[i][j - 1] + l[j]);

		}
	}
	cout << dp[k][n - 1] << '\n';
}
