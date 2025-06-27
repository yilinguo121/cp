#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	int a = 0, b = 0, c = 0;
	cin >> s;
	for (int i = 0;i < 6;i++) {
		if (s[i] == '1') a++;
		if (s[i] == '2') b++;
		if (s[i] == '3') c++;
	}
	if (a == 1 and b == 2 and c == 3) cout << "Yes";
	else cout << "No";
}

