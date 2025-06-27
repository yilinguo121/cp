#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		int t = 0;
		int ans = 0;
		for (int i = 0; i < s.size();i++) {
			if (s[i] == 'O') t++;
			else t = 0;
			ans += t;
		}
		cout << ans << '\n';
	}
}

