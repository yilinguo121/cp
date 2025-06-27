#include<bits/stdc++.h>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int k;
	set<int> st;
	for (int i = 0;i < n;i++) {
		cin >> k;
		if (k == 1) {
			int x;
			cin >> x;
			st.insert(x);
		}
		if (k == 2) {
			int l, r;
			cin >> l >> r;
			while (1) {
				if (st.lower_bound(l) != st.end()) {
					if (*st.lower_bound(l) <= r) {
						st.erase(*st.lower_bound(l));
					}
					else {
						break;
					}
				}
				else {
					break;
				}
			}
		}
		if (st.size() == 1) {
			cout << 1 << ' ';
			cout << *st.begin() << '\n';
		}
		else if (st.size() == 0) {
			cout << 0 << '\n';
		}
		else{
			cout << 2 << ' ';
			cout << *st.begin() << ' ' << *--st.end() << '\n';
		}
	}
}
