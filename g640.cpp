#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	set<long long> st;
	while (n--) {
		long long t;
		cin >> t;
		st.insert(t);
	}
	long long ans = 0;
	while (m--) {
		long long t;
		cin >> t;
		if (st.lower_bound(t) != st.end()) ans += *st.lower_bound(t);
	}
	cout << ans;
}

