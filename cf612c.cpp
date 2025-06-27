#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
string s;
bool check(char x, char y) {
	if (x == '<' and y == '>') return 1;
	if (x == '{' and y == '}') return 1;
	if (x == '[' and y == ']') return 1;
	if (x == '(' and y == ')') return 1;
	return 0;
}
bool is_left(char x) {
	if (x == '<' or x == '{' or x == '[' or x == '(') return 1;
	return 0;
}
bool is_right(char x) {
	if (x == '>' or x == '}' or x == ']' or x == ')') return 1;
	return 0;
}
vector<char> v;
int main() {
	cin >> s;
	int ans = 0;
	for (int i = 0;i < s.size();i++) {
		v.push_back(s[i]);
		while (v.size() >= 2 and check(v[v.size() - 2], v[v.size() - 1])) {
			v.pop_back();
			v.pop_back();
		}
		while (v.size() >= 2 and is_left(v[v.size() - 2]) and is_right(v[v.size() - 1])) {
			ans++;
			v.pop_back();
			v.pop_back();
		}
	}
	if (v.size() == 0) cout << ans;
	else cout << "Impossible";
}
