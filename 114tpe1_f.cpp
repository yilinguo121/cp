#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
const long long mod = 1000000007;
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	int mn = INF;
	for (auto &x : v) cin >> x;
	sort(v.begin(), v.end());
	for (int i = 1;i < n;i++) mn = min(mn, abs(v[i] - v[i - 1]));
	int ans = 0;
	do {
		int now = INF;
		for (int i = 1;i < n;i++) now = min(now, abs(v[i] - v[i - 1]));
		ans = (ans + (now == mn)) % mod;
	} while (next_permutation(v.begin(), v.end()));
	cout << ans;
}
