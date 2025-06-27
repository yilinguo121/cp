#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	while (cin >> s) {
		if (s == "0") break;
		int ans = 0;
		bool f = 1;
		for (int i = 0;i < s.size();i++) {
			if (s[i] >= 'a' and s[i] <= 'z') ans += s[i] - 'a' + 1;
			else if (s[i] >= 'A' and s[i] <= 'Z') ans += s[i] - 'A' + 1;
			else {
				cout << "Fail\n";
				f = 0;
				break;
			}
		}
		if (f) cout << ans << '\n';
	}
}

