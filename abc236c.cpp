#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, q;
	cin >> n >> q;
	set<string> st;
	string s[n];
	for (int i = 0;i <n;i++) cin >> s[i];
	while (q--) {
		string t;
		cin >> t;
		st.insert(t);
	}
	for (int i = 0;i < n;i++) {
		if (st.find(s[i]) != st.end()) cout << "Yes\n";
		else cout << "No\n";
	}
}

