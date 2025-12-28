#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	queue<int> q;
	multiset<int> st;
	while (n--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x;
			cin >> x;
			q.push(x);
		}
		if (t == 2) {
			if (st.empty()) {
				cout << q.front() << '\n';
				q.pop();
			}
			else {
				cout << *st.begin() << '\n';
				st.erase(st.begin());
			}
		}
		if (t == 3) {
			while (!q.empty()) {
				st.insert(q.front());
				q.pop();
			}
		}
	}
}

