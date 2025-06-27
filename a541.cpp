#include<bits/stdc++.h>
using namespace std;
int main() {
	set<string> st;
	int n;
	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		st.insert(s);
	}
	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		if (st.find(s) != st.end()) cout << "yes\n";
		else {
			cout << "no\n";
			st.insert(s);
		}
	}
}
