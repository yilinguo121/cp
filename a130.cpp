#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	for (int i = 1;i <= t;i++) {
		cout << "Case #" << i << ":\n";
		int MAX = 0;
		vector<string> ans;
		for (int i = 0;i < 10;i++) {
			string s;
			int x;
			cin >> s >> x;
			if (x > MAX) {
				ans.clear();
				MAX = x;
			}
			if (x == MAX) ans.push_back(s);
		}
		for (auto s : ans) cout << s << '\n';
	}
}

