#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	multiset<int> st;
	while (n--) {
		int h;
		cin >> h;
		st.insert(h);
	}
	while (m--) {
		int t;
		cin >> t;
		if (st.size() == 0) cout << -1 << '\n';
		else if (st.upper_bound(t) == st.begin() or --st.upper_bound(t) == st.end()) cout << -1 << '\n';
		else {
			cout << *--st.upper_bound(t) << '\n';
			st.erase(--st.upper_bound(t));
		}
	}
}

