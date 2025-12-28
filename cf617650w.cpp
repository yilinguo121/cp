#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n;
	cin >> n;
	vector<int> dp(n + 1);
	while (n--) {
		int x;
		cin >> x;
		dp[x] = max(dp[x], dp[x - 1] + 1);
	}
	cout << *max_element(dp.begin(), dp.end());
}
