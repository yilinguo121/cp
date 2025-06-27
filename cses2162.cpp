#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	set<int> st;
	for (int i = 1;i <= n;i++) st.insert(i);
	auto pos = st.begin();
	while (st.size() > 1) {
		if (st.upper_bound(*pos) == st.end()) {
			cout << *st.begin() << ' ';
			st.erase(st.begin());
			pos = st.begin();
		}
		else {
			pos = st.upper_bound(*pos);
			cout << *pos << ' ';
			st.erase(pos);
			auto t = st.upper_bound(*pos);
			if (t == st.end()) pos = st.begin();
			else pos = t;
		}
	}
	cout << *st.begin();
}

