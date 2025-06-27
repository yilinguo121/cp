#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m, h, k;
	string s;
	set<pair<int ,int>> st;
	cin >> n >> m >> h >> k >> s;
	int nx = 0, ny = 0;
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	for (int i = 0;i < m;i++) {
		int x, y;
		cin >> x >> y;
		st.insert({x, y});
	}
	for (int i = 0;i < n;i++) {
		int way;
		if (s[i] == 'R') way = 0;
		if (s[i] == 'L') way = 1;
		if (s[i] == 'U') way = 2;
		if (s[i] == 'D') way = 3;
		nx += dx[way];
		ny += dy[way];
		h--;
		if (h < 0) {
			cout << "No";
			return 0;
		}
		if (st.find({nx, ny}) != st.end()) {
			if (h < k) {
				h = k;
				st.erase({nx, ny});
			}
		}
	}
	cout << "Yes";
}

