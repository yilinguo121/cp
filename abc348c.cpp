#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	map<int, set<int>> mp;
	for (int i = 0;i < n;i++) {
		int a, c;
		cin >> a >> c;
		mp[c].insert(a);
	}
	set<int> st;
	for (auto x : mp) {
		st.insert(*x.second.begin());
	}
	cout << *st.rbegin();
}

