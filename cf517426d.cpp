#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	deque<pair<int, int>> v[26];
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			char c;
			cin >> c;
			int t = c - 'a';
			v[t].push_back({i + 1, j + 1});
		}
	}
	int q;
	cin >> q;
	while (q--) {
		char c;
		cin >> c;
		int t = c - 'a';
		if (v[t].size() == 0) {
			cout << "-1 -1\n";
			continue;
		}
		cout << v[t][0].first << ' ' << v[t][0].second << '\n';
		v[t].pop_front();
	}
}
