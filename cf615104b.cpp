#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	vector<pair<char, int>> v;
	string s;
	cin >> s;
	char c = ' ';
	int cnt = 1;
	for (auto x : s) {
		if (x == c) cnt++;
		else {
			if (c != ' ') v.push_back({c, cnt});
			c = x;
			cnt = 1;
		}
	}
	v.push_back({c, cnt});
	int q;
	cin >> q;
	while (q--) {
		char type;
		int x;
		cin >> type >> c >> x;
		cnt = 0;
		if (type == 'A') {
			if (v.back().first == c) v.back().second += x;
			else v.push_back({c, x});
		}
		else {
			while (!v.empty() and x) {
				if (v.back().first == c) {
					if (v.back().second > x) {
						cnt += x;
						v.back().second -= x;
						x = 0;
					}
					else {
						cnt += v.back().second;
						x -= v.back().second;
						v.pop_back();
					}
				}
				else {
					cnt += v.back().second;
					v.pop_back();
				}
			}
			cout << cnt << '\n';
		}
	}
}

