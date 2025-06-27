#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> p(n);
	vector<int> v(n);
	set<int> st;
	for (int i = 0;i < n;i++) {
		cin >> v[i];
		st.insert(v[i]);
		p[i].second = i;
		p[i].first = v[i];
	}
	sort(v.begin(), v.end());

	vector<int> ans(n);
	while (st.size()) {
		int t = *st.rbegin();

	}
}

