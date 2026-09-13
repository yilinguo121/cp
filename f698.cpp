#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	stack<int> st;
	string s;
	while (cin >> s) {
		if (s != "+" and s != "-" and s != "*" and s != "/") st.push(stoi(s));
		else {
			int b = st.top();
			st.pop();
			int a = st.top();
			st.pop();
			if (s == "+") st.push(a + b);
			if (s == "-") st.push(a - b);
			if (s == "*") st.push(a * b);
			if (s == "/") st.push(a / b);
		}
	}
	cout << st.top();
}
