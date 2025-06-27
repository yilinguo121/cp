#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	while (getline(cin, s)) {
		bool f = 1;
		for (int i = 0;i < s.size();i++) {
			if (s[i] == '!') f = 0;
		}
		if (f) cout << "NO\n";
		else cout << "YES\n";
	}
}

