#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	string s;
	cin >> s;
	bool flag = 1;
	for (int i = 0;i < s.size();i++) {
		char x = s[i];
		if (x == '#') {
			if (flag) {
				cout << i + 1 << ',';
				flag = 0;
			}
			else {
				cout << i + 1 << '\n';
				flag = 1;
			}
		}
	}
}

