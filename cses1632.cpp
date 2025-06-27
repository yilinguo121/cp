#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
bool cmp (pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}
int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> v(n);
	for (auto &[x, y] : v) cin >> x >> y;
	sort(v.begin(), v.end(), cmp);
	multiset<int> st;
	int ans = 0;
	for (auto [x, y] : v) {
		auto it = st.upper_bound(x);
		if (it != st.begin()) {
			st.erase(prev(it));
			st.insert(y);
			ans++;
			continue;
		}
		if (st.size() < k) {
			st.insert(y);
			ans++;
		}
	}
	cout << ans;
}
