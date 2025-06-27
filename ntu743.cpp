#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
bool cmp(pair<int, int> a, int b) {
	return a.first > b;
}
signed main() {
	IO
	int n;
	cin >> n;
	vector<int> h(n + 1), p(n + 1);
	for (int i = 1;i <= n;i++) cin >> h[i];
	for (int i = 1;i <= n;i++) cin >> p[i];
	vector<pair<int, int>> st;
	int ans = 0;
	for (int i = 1;i <= n;i++) {
		int j = lower_bound(st.begin(), st.end(), h[i] + p[i], cmp) - st.begin();
		if (j) ans += i - st[j - 1].second - 1;
		else ans += i - 1;
		while (!st.empty() and h[i] >= st.back().first) st.pop_back();
		st.push_back({h[i], i});
	}
	cout << ans;
}
