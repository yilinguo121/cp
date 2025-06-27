#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (count(s.begin(), s.end(), 'T') > n / 2) cout << "T";
	else if (count(s.begin(), s.end(), 'A') > n / 2) cout << "A";
	else {
		int a = 0, t = 0;
		for (int i = 0;i < n;i++) {
			if (s[i] == 'A') a++;
			else t++;
			if (a == n / 2) {
				cout << 'A';
				break;
			}
			if (t == n / 2) {
				cout << 'T';
				break;
			}
		}
	}
}

