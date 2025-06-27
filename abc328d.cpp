#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	string s;
	vector<char> v;
	cin >> s;
	for (int i = 0;i < s.size();i++) {
		v.push_back(s[i]);
		int n = v.size() - 1;
		if (v.size() >= 3 and v[n - 2] == 'A' and v[n - 1] == 'B' and v[n] == 'C') {
			for (int j = 0;j < 3;j++) v.pop_back();
		}
	}
	for (auto x : v) cout << x;
}
