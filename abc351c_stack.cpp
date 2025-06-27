#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int n;
	cin >> n;
	stack<int> st;
	int x;
	while (n--) {
		cin >> x;
		while (st.size() and x == st.top()) {
			x++;
			st.pop();
		}
		st.push(x);
	}
	cout << st.size();
}

