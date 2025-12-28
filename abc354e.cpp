#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<int> a, b, dp;
int n;
bool win(int t) {
	int &now = dp[t];
	if (now != -1) return now;
	for (int i = 0;i < n;i++) {
		if (t & (1 << i)) continue;
		for (int j = i + 1;j < n;j++) {
			if (t & (1 << j)) continue;
			if (a[i] != a[j] and b[i] != b[j]) continue;
			if (!win(t | (1 << i) | (1 << j))) return now = 1;
		}
	}
	return now = 0;
}
int main() {
	cin >> n;
	a.resize(n);
	b.resize(n);
	dp.assign((1 << n), -1);
	for (int i = 0;i < n;i++) cin >> a[i] >> b[i];
	dp[(1 << n) - 1] = 0;
	cout << (win(0) ? "Takahashi" : "Aoki");
}
