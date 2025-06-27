#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	bool flag = 0;
	bool c = 0;
	for (int i = s.size() - 1;i >= 0;i--) {
		if (flag and s[i] == '0') cout << 0;
		if (s[i] == '0') continue;
		else {
			c = 1;
			cout << s[i];
			flag = 1;
		}
	}
	if (!c) cout << 0;
}

