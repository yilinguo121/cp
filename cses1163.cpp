#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n, m;
	cin >> n >> m;
	set<int> st;
	multiset<int> dis;
	st.insert(0);
	st.insert(n);
	dis.insert(n);
	while (m--) {
		int x;
		cin >> x;
		if (st.find(x) != st.end()) {
			cout << *dis.rbegin() << ' ';
			continue;
		}
		int r = *st.upper_bound(x), l = *prev(st.upper_bound(x));
		dis.erase(dis.find(r - l));
		dis.insert(r - x);
		dis.insert(x - l);
		st.insert(x);
		cout << *dis.rbegin() << ' ';
	}
}
