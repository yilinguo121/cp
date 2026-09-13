#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
string s;
int i = 0;
int num() {
	int x = 0;
	while (i < s.size() and s[i] >= '0' and s[i] <= '9') x = x * 10 + s[i++] - '0';
	return max(1, x);
}
map<string, int> dfs() {
	map<string, int> now;
	while (i < s.size()) {
		if (s[i] == '(') {
			i++;
			auto in = dfs();
			if (s[i] == ')') i++;
			int t = num();
			for (auto &[atom, cnt] : in) now[atom] += cnt * t;
		}
		if (s[i] == ')') break;
		if (s[i] >= 'A' and s[i] <= 'Z') {
			string atom;
			atom += s[i++];
			while (i < s.size() and 'a' <= s[i] and s[i] <= 'z') atom += s[i++];
			now[atom] += num();
		}
	}
	return now;
}
int main() {
	IO
	cin >> s;
	cout << s << '\n';
	for (auto [atom, cnt] : dfs()) cout << atom << ":" << cnt << '\n';
}
