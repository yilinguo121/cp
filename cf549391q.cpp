#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int q;
	cin >> q;
	set<int> st;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int x;
			cin >> x;
			auto b = st.insert(x);
			if (!b.second) st.erase(x);
		}
		else {
			string s;
			int x;
			cin >> s >> x;
			if (s == ">") {
				auto pos = st.upper_bound(x);
				if (pos == st.end()) cout << "NaN\n";
				else cout << *pos << '\n';
			}
			if (s == ">=") {
				auto pos = st.lower_bound(x);
				if (pos == st.end()) cout << "NaN\n";
				else cout << *pos << '\n';
			}
			if (s == "<") {
				auto pos = st.lower_bound(x);
				if (pos == st.begin()) cout << "NaN\n";
				else cout << *--pos << '\n';
			}
			if (s == "<=") {
				auto pos = st.upper_bound(x);
				if (pos == st.begin()) cout << "NaN\n";
				else cout << *--pos << '\n';
			}
		}
	}
}

