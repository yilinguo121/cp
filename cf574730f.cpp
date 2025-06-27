#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int m;
	cin >> m;
	vector<int> v(m);
	for (int i = 0;i < m;i++) {
		cin >> v[i];
	}
	long long ans = 500;
	for (int i = 0;i < (1 << m);i++) {
		set<int> st;
		int last = 0;
		st.insert(last);
		for (int j = 0;j < m;j++) {
			if (i & (1 << j)) last += v[j];
			else last -= v[j];
			st.insert(last);
		}
		long long sz = st.size();
		ans = min(ans, sz);
	}
	cout << ans;
}

