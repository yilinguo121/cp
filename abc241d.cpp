#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int q;
	cin >> q;
	multiset<long long> st;
	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			long long x;
			cin >> x;
			st.insert(x);
		}
		if (c == 2) {
			long long x;
			int k;
			cin >> x >> k;
			auto pos = st.upper_bound(x);
			bool flag = 1;
			for (int i = 0;i < k;i++) {
				if (pos == st.begin()) {
					cout << -1 << '\n';
					flag = 0;
					break;
				}
				pos--;
			}
			if (flag) cout << *pos << '\n';
		}
		if (c == 3) {
			long long x;
			int k;
			cin >> x >> k;
			auto pos = st.lower_bound(x);
			if (pos == st.end()) {
				cout << "-1\n";
				continue;
			}
			bool flag = 1;
			for (int i = 1;i < k;i++) {
				pos++;
				if (pos == st.end()) {
					cout << -1 << '\n';
					flag = 0;
					break;
				}
			}
			if (flag) cout << *pos << '\n';
		}
	}
}

