#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, q;
	cin >> n >> q;
	set<pair<int, int>> st;
	while (q--) {
		int type, a, b;
		cin >> type >> a >> b;
		if (type == 1) st.insert({a, b});
		else if (type == 2) st.erase({a, b});
		else {
			if (st.find({a, b}) != st.end() and st.find({b, a}) != st.end()) cout << "Yes\n";
			else cout << "No\n";
		}
	}
}

