#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	multiset<int> st;
	st.insert(-1e18);
	st.insert(1e18);
	for (int i = 0;i < n;i++) {
		int a;
		cin >> a;
		st.insert(a);
	}
	while (n--) {
		int x, k;
		cin >> x >> k;
		auto upper = st.upper_bound(x);
		auto lower = --st.upper_bound(x);
		int ans;
		while (k--) {
			if (abs(*lower - x) <= abs(*upper - x)) {
				ans = *lower;
				lower--;
			}
			else {
				ans = *upper;
				upper++;
			}
		}
		cout << ans << '\n';
		st.erase(st.find(ans));
	}
}

