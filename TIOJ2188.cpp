#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int t = 0;
	for (int i = 0;i < s.size();i++) {
		if (islower(s[i])) {
			if (!t) cout << s[i];
			else {
				while (t--) cout << s[i];
			}
			t = 0;
		}
		else {
			t = t * 10 + s[i] - '0';
		}
	}
}

