#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int n, m;
	cin >> n >> m;
	while (m--) {
		stack<int> st, v;
		for (int i = n;i > 0;i--) st.push(i);
		bool flag = 1;
		for (int i = 0;i < n;i++) {
			int x;
			cin >> x;
			if (!st.empty() and st.top() == x) st.pop();
			else if (!v.empty() and v.top() == x) v.pop();
			else {
				while (!st.empty() and st.top() != x) {
					v.push(st.top());
					st.pop();
				}
				if (st.empty()) flag = 0;
				else st.pop();
			}
		}
		cout << (flag ? "Y\n" : "N\n");
	}
}

