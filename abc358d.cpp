#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n, m;
	cin >> n >> m;
	multiset<int> st;
	for (int i = 0;i < n;i++) {
		int t;
		cin >> t;
		st.insert(t);
	}
	int ans = 0;
	for (int i = 0;i < m;i++) {
		int t;
		cin >> t;
		if (st.lower_bound(t) == st.end()) {
			cout << -1;
			return 0;
		}
		ans += *st.lower_bound(t);
		st.erase(st.lower_bound(t));
	}
	cout << ans;
}
