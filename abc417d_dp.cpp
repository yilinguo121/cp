#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
struct type {
	int p;
	int a;
	int b;
};
int n;
vector<type> v;
vector<vector<int>> dp(1001, vector<int> (10001, -1));
int f(int now, int id) {
	if (id == n) return dp[now][id] = now;
	if (dp[now][id] != -1) return dp[now][id];
	return dp[now][id] = f((now <= v[id].p ? now + v[id].a : max(0, now - v[id].b)), id + 1);
}
int main() {
	cin >> n;
	v.resize(n);
	vector<int> sum(1);
	for (auto &[p, a, b] : v) {
		cin >> p >> a >> b;
		sum.push_back(sum.back() + b);
	}
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		if (x <= 1000) cout << f(x, 0) << '\n';
		else {
			auto pos = lower_bound(sum.begin(), sum.end(), x - 1000);
			if (pos == sum.end()) cout << x - sum.back() << '\n';
			else cout << f(max(0, x - *pos), pos - sum.begin()) << '\n';
		}
	}
}
