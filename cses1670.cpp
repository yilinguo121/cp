#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
string bfs[1048576];
int dis[1048576];
int main() {
	unordered_set<string> st;
	bfs[0].resize(9);
	for (int i = 0;i < 9;i++) {
		char c;
		cin >> c;
		bfs[0][i] = c;
	}
	st.insert(bfs[0]);
	dis[0] = 0;
	pair<int, int> p[12] = {
		{0, 1}, {1, 2}, {3, 4}, {4, 5}, {6, 7}, {7, 8}, {0, 3}, {3, 6}, {1, 4}, {4, 7}, {2, 5}, {5, 8}
	};
	for (int i = 0, j = 1;i < j;i++) {
		if (bfs[i] == "123456789") {
			cout << dis[i];
			return 0;
		}
		for (auto [x, y] : p) {
			bfs[j] = bfs[i];
			swap(bfs[j][x], bfs[j][y]);
			if (st.insert(bfs[j]).second) dis[j++] = dis[i] + 1;
		}
	}
}

