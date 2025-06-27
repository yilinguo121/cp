#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int l =  1;
	for (int i = 0;i < s.size();i++) {
		if (i != 0 and s[i] == '|') {
			cout << i - l << ' ';
			l = i + 1;
		}
	}
}

