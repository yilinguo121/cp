#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, m;
	cin >> n >> m;
	vector<char> v(max(n, m));
	int now;
	for (int i = 0;i < max(n, m);i++) {
		cin >> v[i];
		if (v[i] == 'R') now = i;
	}
	bool l = 1, r = 1; // 紀錄需不需要繼續往左/右邊走
	pair<int, int> l_best = {-1, -1}, r_best = {-1, -1}; // 紀錄Raymond到左邊、右邊最近的出口與距離
	for (int i = 0;i < max(n, m);i++) {
		if (r and now + i < max(n, m)) {
			if (v[now + i] == '#' or v[now + i] == 'F') r = 0;
			else if (v[now + i] == 'X') {
				r_best = {now + i, i};
				r = 0;
			}
		}
		if (l and now - i >= 0) {
			if (v[now - i] == '#' or v[now - i] == 'F') l = 0;
			else if (v[now - i] == 'X') {
				l_best = {now - i, i};
				l = 0;
			}
		}
	}
	if (r_best.first == -1 and l_best.first == -1) {
		cout << "No";
		return 0;
	}
	if (r_best.first != -1) {
		int dist = 0;
		while (++r_best.first < max(n, m)) {
			dist++;
			if (v[r_best.first] == '#') break;
			if (v[r_best.first] == 'F' and dist <= r_best.second) {
				cout << "No";
				return 0;
			}
		}
	}
	if (l_best.first != -1) {
		int dist = 0;
		while (l_best.first--) {
			dist++;
			if (v[l_best.first] == '#') break;
			if (v[l_best.first] == 'F' and dist <= l_best.second) {
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
}
