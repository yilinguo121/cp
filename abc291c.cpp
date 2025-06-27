#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	string s;
	cin >> n >> s;
	int nx = 0, ny = 0;
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	set<pair<int, int>> st;
	for (int i = 0;i < n;i++) {
		if (st.find({nx, ny}) != st.end()) {
			cout << "Yes\n";
			return 0;
		}
		st.insert({nx, ny});
		int way;
		if (s[i] == 'R') way = 0;
		if (s[i] == 'L') way = 1;
		if (s[i] == 'U') way = 2;
		if (s[i] == 'D') way = 3;
		nx += dx[way];
		ny += dy[way];
	}
	if (st.find({nx, ny}) != st.end()) {
		cout << "Yes\n";
		return 0;
	}
	cout << "No";
}

