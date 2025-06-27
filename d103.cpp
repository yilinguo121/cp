#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0, j = 1;i < 11;i++) {
		if (s[i] == '-') continue;
		sum += j * (s[i] - '0');
		j++;
	}
	if ((sum % 11 == 10 and s[s.size() - 1] == 'X') or sum % 11 == s[s.size() - 1] - '0') cout << "Right";
	else {
		for (int i = 0;i < 12;i++) cout << s[i];
		if (sum % 11 == 10) cout << 'X';
		else cout << sum % 11;
	}
}

