#include <bits/stdc++.h>
using namespace std;
int main() {
	int x, n;
	cin >> x >> n;
	int l = 0, r = 0;
	set<int> st;
	while (n--) {
		int t;
		cin >> t;
		if (t < x) l++;
		else r++;
		st.insert(t);
	}
	if (l > r) cout << l << ' ' << *st.begin();
	else cout << r << ' ' << *st.rbegin();
}

