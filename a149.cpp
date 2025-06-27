#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	int n;
	cin >> n;
	while (n--) {
		cin >> s;
		long long ans = 1;
		for (int i = 0;i < s.size();i++) ans *= (s[i] - '0');
		cout << ans << '\n';
	}
}

