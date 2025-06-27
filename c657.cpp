#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	while (cin >> s) {
		int n = s.size();
		int MAX = 0;
		char ans;
		int now = 1;
		for (int i = 1;i < n;i++) {
			if (s[i] == s[i - 1]) now++;
			else now = 1;
			if (now > MAX) {
				MAX = now;
				ans = s[i];
			}
		}
		cout << ans << ' ' << MAX << '\n';
	}
}

