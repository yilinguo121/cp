#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int n = s.size();
	set<string> st;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			st.insert(s.substr(i, j));
		}
	}
	cout << st.size();
}

