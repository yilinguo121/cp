#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<char> st, v;
	while (n--) {
		int t;
		cin >> t;
		if (t == 1) {
			char c;
			cin >> c;
			if (c == '(') {
				st.push_back('(');
				v.push_back(0);
			}
			else {
				if (!st.empty() and st.back() == '(') {
					st.pop_back();
					v.push_back(2);
				}
				else {
					st.push_back(')');
					v.push_back(1);
				}
			}
		}
		else {
			if (!v.back() or v.back() == 1) st.pop_back();
			else st.push_back('(');
			v.pop_back();
		}
		cout << (st.empty() ? "Yes\n" : "No\n");
	}
}

