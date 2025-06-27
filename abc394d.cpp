#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	string s;
	vector<char> v;
	cin >> s;
	for (int i = 0;i < s.size();i++) {
		v.push_back(s[i]);
		int n = v.size() - 1;
		if (v.size() >= 2 and ((v[n - 1] == '(' and v[n] == ')') or (v[n - 1] == '[' and v[n] == ']') or (v[n - 1] == '<' and v[n] == '>'))) {
			for (int j = 0;j < 2;j++) v.pop_back();
		}
	}
	cout << (v.size() != 0 ? "No" : "Yes");
}
