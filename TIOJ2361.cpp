#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, d;
	cin >> n >> d;
	while (n--) {
		string s;
		cin >> s;
		set<string> st;
		while (1) {
			while (s.size() < d) s = '0' + s;
			if (st.find(s) != st.end()) break;
			st.insert(s);
			sort(s.begin(), s.end());
			string t = s;
			reverse(t.begin(), t.end());
			s = to_string(stoll(t) - stoll(s));
			while (s.size() < d) s = '0' + s;
		}
		cout << stoll(s) << '\n';
	}
}

