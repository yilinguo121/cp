#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int l, n;
	cin >> l >> n;
	set<int> st;
	st.insert(l);
	st.insert(0);
	long long ans = 0;
	while (n--) {
		int p;
		cin >> p;
		ans += *st.upper_bound(p) - *--st.lower_bound(p);
		st.insert(p);
	}
	cout << ans;
}

