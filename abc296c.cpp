#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	set<int> st;
	for (int i = 0;i < n;i++) {
		cin >> v[i];
		st.insert(v[i]);
	}
	for (int i = 0;i < n;i++) {
		if (st.find(x + v[i]) != st.end()) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
}

