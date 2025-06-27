#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
int sum(int x, int y) {
	if (x > y) return 0;
	return (x + y) * (y - x + 1) / 2;
}
signed main() {
	IO
	int n, q;
	cin >> n >> q;
	vector<pair<int, int>> st;
	st.push_back({1, n});
	while(q--) {
		int k;
		cin >> k;
		int ans = st.back().first - 1;
		if (st.back().first == st.back().second) st.pop_back();
		else st.back().first++;
		int cnt = k;
		while (cnt > 0 and !st.empty()) {
			if (st.back().second - st.back().first + 1 > cnt) {
				ans += sum(st.back().first, st.back().first + cnt - 1);
				st.back().first += cnt;
				break;
			}
			else {
				ans += sum(st.back().first, st.back().second);
				cnt -= st.back().second - st.back().first + 1;
				st.pop_back();
			}
		}
		ans -= sum(1, k);
		if (k > 0) st.push_back({1, k});
		cout << ans << ' ';
	}
}

