#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	vector<vector<int>> v(n);
	vector<int> cnt(n);
	for (int i = 0;i < n;i++) {
		for (int j = i + 1;j < n;j++) {
			if (a[i] < a[j]) {
				v[i].push_back(j);
				cnt[j]++;
			}
		}
	}
	queue<int> q;
	vector<int> dp(n);
	for (int i = 0;i < n;i++) {
		if (!cnt[i]) {
			q.push(i);
			dp[i] = 1;
		}
	}
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		for (auto nt : v[t]) {
			dp[nt] = max(dp[nt], dp[t] + 1);
			if (!--cnt[nt]) q.push(nt);
		}
	}
	cout << *max_element(dp.begin(), dp.end());
}

