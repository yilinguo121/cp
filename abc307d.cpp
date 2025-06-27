#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<char> st;
	int flag = 0;
	for (int i = 0;i < n;i++) {
		if (s[i] == ')' and flag) {
			while (st.back() != '(') {
				st.pop_back();
			}
			st.pop_back();
			flag--;
			continue;
		}
		if (s[i] == ')') flag = 0;
		if (s[i] == '(') flag++;
		st.push_back(s[i]);
	}
	for (auto x : st) cout << x;
}

