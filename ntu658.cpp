#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	IO
	stack<int> st;
	int n;
	cin >> n;
	while (n--) {
		int t, x;
		cin >> t;
		if (t == 1) {
			cin >> x;
			st.push(x);
		}
		if (t == 2) {
			if (st.empty()) cout << "QQ\n";
			else st.pop();
		}
		if (t == 3) {
			if (st.empty()) cout << "QQ\n";
			else cout << st.top() << '\n';
		}
		if (t == 4) cout << st.size() << '\n';
	}
}

