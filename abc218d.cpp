#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	set<pair<int, int>> st;
	for (int i = 0;i < n;i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
		st.insert({x, y});
	}
	int ans = 0;
	for (int i = 0;i < n;i++) {
		for (int j = i + 1;j < n;j++) {
			if (v[i].first == v[j].first or v[i].second == v[j].second) continue;
			if (st.find({v[i].first, v[j].second}) != st.end() and st.find({v[j].first, v[i].second}) != st.end()) ans++;
		}
	}
	cout << ans / 2;
}

