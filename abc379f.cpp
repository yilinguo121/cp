#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, q;
	cin >> n >> q;
	vector<int> h(n + 1), ans(q + 1), st;
	vector<vector<pair<int, int>>> v(n + 1);
	for (int i = 1;i <= n;i++) cin >> h[i];
	for (int i = 1;i <= q;i++) {
		int l, r;
		cin >> l >> r;
		v[l].push_back({r, i});
	}
	for (int i = n;i >= 1;i--) {
		for (auto [j, k] : v[i]) ans[k] = lower_bound(st.begin(), st.end(), j, greater<>()) - st.begin();
		while (!st.empty() and h[i] >= h[st.back()]) st.pop_back();
		st.push_back(i);
	}
	for (int i = 1;i <= q;i++) cout << ans[i] << '\n';
}
