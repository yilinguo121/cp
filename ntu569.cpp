#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	long long ans = 0;
	for (int i = 0;i < s.size();i++) {
		int l = i, r = i;
		while (1) {
			l--;
			r++;
			if (l < 0 or r >= s.size() or s[l] != s[r]) break;
			ans++;
		}
		l = i;
		r = i + 1;
		while (l >= 0 and r < s.size()) {
			if (s[l] != s[r]) break;
			ans++;
			l--;
			r++;
		}
	}
	cout << ans;
}

