#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0;i < s.size();i++) {
		if (i < s.size() - 1) {
			if (s[i] == '0' and s[i + 1] == '0') {
				ans++;
				i++;
				continue;
			}
		}
		ans++;
	}
	cout << ans;
}
