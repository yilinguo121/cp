#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	while (t--) {
		getline(cin, s);
		map<char, int> mp;
		int ans = 0;
		for (auto c : s) {
			if (c >= 'a' and c <= 'z') {
				mp[c - 'a']++;
				ans = max(ans, mp[c - 'a']);
			}
			if (c >= 'A' and c <= 'Z') {
				mp[c - 'A']++;
				ans = max(ans, mp[c - 'A']);
			}
		}
		for (char c = 'a';c <= 'z';c++) {
			if (mp[c - 'a'] == ans) cout << c;
		}
		cout << '\n';
	}
}
